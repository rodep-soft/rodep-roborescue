#include <iostream>
#include <vector>
#include <memory>
#include <boost/asio.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp> 
#include <custom_interfaces/msg/driver_velocity.hpp>

using namespace std;
using namespace boost::asio;
using std::placeholders::_1;

// Constants
constexpr int ROBOCLAW_ADDRESS = 0x80;
constexpr int M1_MOTOR_COMMAND = 6;
constexpr int M2_MOTOR_COMMAND = 7;
constexpr int M1_ENCODER_COMMAND = 92;
constexpr int M2_ENCODER_COMMAND = 93;
constexpr int M1_SET_PID_CONSTANTS_COMMAND = 28;
constexpr int M2_SET_PID_CONSTANTS_COMMAND = 29;
constexpr int SERIAL_BAUD_RATE = 38400;
constexpr int SERIAL_TIMEOUT_MS = 1000;
constexpr int RESET_QUAD_ENCODER = 20;
constexpr int QPPS = 86646;

// RoboclawDriver Class
class RoboclawDriver {
public:
    explicit RoboclawDriver(const string& port) : io(), serial(io, port) {
        try {
            serial.set_option(serial_port_base::baud_rate(SERIAL_BAUD_RATE));
            serial.set_option(serial_port_base::character_size(8));
            serial.set_option(serial_port_base::parity(serial_port_base::parity::none));
            serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
            serial.set_option(serial_port_base::flow_control(serial_port_base::flow_control::none));
        } catch (const boost::system::system_error& e) {
            throw runtime_error("Failed to configure serial port: " + string(e.what()));
        }
    }

    bool setMotorVelocity(int command, double pulse_per_sec) {
        vector<uint8_t> data = {ROBOCLAW_ADDRESS, static_cast<uint8_t>(command)};
        appendInt32(data, static_cast<int>(pulse_per_sec));
        appendCRC(data);
        return sendRoboclawCommand(data);
    }

    bool setPIDConstants(int command, int K_p, int K_i, int K_d, int qpps) {
        vector<uint8_t> data = {ROBOCLAW_ADDRESS, static_cast<uint8_t>(command)};
        appendInt32(data, K_d);
        appendInt32(data, K_p);
        appendInt32(data, K_i);
        appendInt32(data, qpps);
        appendCRC(data);
        return sendRoboclawCommand(data);
    }

    bool resetEncoders() {
        vector<uint8_t> data = {ROBOCLAW_ADDRESS, RESET_QUAD_ENCODER};
        appendCRC(data);
        return sendRoboclawCommand(data);
    }

private:
    io_service io;
    serial_port serial;

    bool sendRoboclawCommand(const vector<uint8_t>& data) {
        try {
            write(serial, buffer(data));
            uint8_t response;
            read(serial, buffer(&response, 1));
            RCLCPP_DEBUG(rclcpp::get_logger("RoboclawDriver"), "Received Response: 0x%02X", response);
            return true;
        } catch (const boost::system::system_error& e) {
            RCLCPP_ERROR(rclcpp::get_logger("RoboclawDriver"), "Serial Communication Error: %s", e.what());
            return false;
        }
    }

    uint16_t calculateCRC(const vector<uint8_t>& data) {
        uint16_t crc = 0;
        for (auto byte : data) {
            crc ^= static_cast<uint16_t>(byte) << 8;
            for (int i = 0; i < 8; i++) {
                crc = (crc & 0x8000) ? (crc << 1) ^ 0x1021 : (crc << 1);
            }
        }
        return crc;
    }

    void appendCRC(vector<uint8_t>& data) {
        uint16_t crc = calculateCRC(data);
        data.push_back(static_cast<uint8_t>(crc >> 8));
        data.push_back(static_cast<uint8_t>(crc & 0xFF));
    }

    void appendInt32(vector<uint8_t>& data, int value) {
        for (int i = 3; i >= 0; --i) {
            data.push_back(static_cast<uint8_t>((value >> (8 * i)) & 0xFF));
        }
    }
};

// ROS2 Driver Node
class Driver : public rclcpp::Node {
public:
    Driver() : Node("driver"), roboclaw("/dev/ttyACM0") {
        declare_parameter("crawler_circumference", 0.39);
        declare_parameter("pulse_per_rev", 512);
        declare_parameter("gearhead_ratio", 66);
        declare_parameter("pulley_ratio", 2);

        crawler_circumference_ = get_parameter("crawler_circumference").as_double();
        pulse_per_rev_ = get_parameter("pulse_per_rev").as_int();
        gearhead_ratio_ = get_parameter("gearhead_ratio").as_int();
        pulley_ratio_ = get_parameter("pulley_ratio").as_int();

        pulse_per_meter_ = (pulse_per_rev_ * gearhead_ratio_ * pulley_ratio_) / crawler_circumference_;

        subscription_ = create_subscription<custom_interfaces::msg::DriverVelocity>(
            "/operator", 10, bind(&Driver::driver_callback, this, _1));

        estop_subscription_ = create_subscription<std_msgs::msg::Bool>(
            "/emergency_stop", 10, bind(&Driver::estop_callback, this, _1));

        init();
    }

private:
    RoboclawDriver roboclaw;
    double crawler_circumference_;
    int pulse_per_rev_;
    int gearhead_ratio_;
    int pulley_ratio_;
    double pulse_per_meter_;
    bool estop_active_ = false;  // E-stop state

    rclcpp::Subscription<custom_interfaces::msg::DriverVelocity>::SharedPtr subscription_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr estop_subscription_;

    double velocity_to_pulse_per_sec(double velocity) const {
        return velocity * pulse_per_meter_;
    }

    void init() {
        roboclaw.setMotorVelocity(M1_MOTOR_COMMAND, 0);
        roboclaw.setMotorVelocity(M2_MOTOR_COMMAND, 0);
        roboclaw.setPIDConstants(M1_SET_PID_CONSTANTS_COMMAND, 0, 0, 0, QPPS);
        roboclaw.setPIDConstants(M2_SET_PID_CONSTANTS_COMMAND, 0, 0, 0, QPPS);
        roboclaw.resetEncoders();
    }

    void driver_callback(const custom_interfaces::msg::DriverVelocity& msg) {
        if (estop_active_) {
            RCLCPP_WARN(get_logger(), "E-stop is active. Ignoring motor commands.");
            return;
        }

        double M1_pulse = velocity_to_pulse_per_sec(msg.m1_vel);
        double M2_pulse = velocity_to_pulse_per_sec(msg.m2_vel);

        if (!roboclaw.setMotorVelocity(M1_MOTOR_COMMAND, M1_pulse)) {
            RCLCPP_ERROR(get_logger(), "Failed to send command to M1 motor");
        }
        if (!roboclaw.setMotorVelocity(M2_MOTOR_COMMAND, M2_pulse)) {
            RCLCPP_ERROR(get_logger(), "Failed to send command to M2 motor");
        }
    }

    void estop_callback(const std_msgs::msg::Bool::SharedPtr msg) {
        estop_active_ = msg->data;

        if (estop_active_) {
            RCLCPP_WARN(get_logger(), "E-stop activated. Stopping all motors.");

            // Send zero velocity commands to stop motors
            roboclaw.setMotorVelocity(M1_MOTOR_COMMAND, 0);
            roboclaw.setMotorVelocity(M2_MOTOR_COMMAND, 0);
        } else {
            RCLCPP_INFO(get_logger(), "E-stop deactivated. Resuming normal operation.");
        }
    }
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Driver>());
    rclcpp::shutdown();
    return 0;
}
