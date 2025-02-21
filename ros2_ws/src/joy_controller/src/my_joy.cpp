#include <boost/asio.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <cmath>
#include <string>

using namespace std;
using namespace boost::asio;
using namespace std::placeholders; // Fix for namespace ambiguity

namespace RoboclawConfig {
    // Serial Communication
    constexpr char PORT[] = "/dev/ttyACM0";
    constexpr unsigned int BAUDRATE = 115200;
    constexpr auto PARITY = serial_port_base::parity::none;
    constexpr auto STOP_BITS = serial_port_base::stop_bits::one;
    constexpr auto FLOW_CONTROL = serial_port_base::flow_control::none;

    // Roboclaw Address
    constexpr uint8_t MAIN_ADDRESS = 0x80;

    // Command Numbers
    constexpr uint8_t CMD_MIXEDSPEED = 37;
    constexpr uint8_t CMD_RESETENC = 20;
    constexpr uint8_t CMD_SETM1ENCODERMODE = 92;
    constexpr uint8_t CMD_SETM2ENCODERMODE = 93;

    // Crawler Specifications
    constexpr double CRAWLER_DIAMETER = 71.1 * 2 / 1000;  // [m]
    constexpr int PULSE = 500 * 2;                       // [count/rotate]
    constexpr int GEAR_HEAD = 66;                        // [rotate/rotate]
    constexpr int PULLEY = 2;                            // [ratio]
    constexpr double ROBOT_RADIUS = 0.3; // [m]

    // Velocity Conversion
    constexpr double TRANS_VARIABLE = (GEAR_HEAD * PULLEY * PULSE) / CRAWLER_DIAMETER;

    // Maximum Speeds
    constexpr double MAX_LINEAR_VEL = 1.0;   // Maximum linear velocity [m/s]
    constexpr double MAX_ANGULAR_VEL = 0.5;  // Maximum angular velocity [rad/s]
}

// Convert velocity to pulse speed for Roboclaw
constexpr int VEL_TO_PULSE(double vel) {
    return static_cast<int>(vel * RoboclawConfig::TRANS_VARIABLE);
}

class Roboclaw {
public:
    Roboclaw() : io_service_(), serial_(io_service_, RoboclawConfig::PORT), crc_(0) {
        serial_.set_option(serial_port_base::baud_rate(RoboclawConfig::BAUDRATE));
        serial_.set_option(serial_port_base::character_size(8));
        serial_.set_option(serial_port_base::parity(RoboclawConfig::PARITY));
        serial_.set_option(serial_port_base::stop_bits(RoboclawConfig::STOP_BITS));
        serial_.set_option(serial_port_base::flow_control(RoboclawConfig::FLOW_CONTROL));
    }

    // void Open() {
    //     if (!serial_.is_open()) {
    //         serial_.open(serial_.get_executor().context());  // Fixed for Boost.Asio
    //     }
    // }

    void Open() {
        if (!serial_.is_open()) {
            boost::system::error_code ec;
            serial_.open(RoboclawConfig::PORT, ec);
            if (ec) {
                cerr << "Failed to open serial port: " << ec.message() << endl;
            }
        }
    }
    

    void Close() {
        if (serial_.is_open()) {
            serial_.close();
        }
    }

    // Write 8 bits
    void WriteByte(uint8_t byte) {
        write(serial_, buffer(&byte, 1));
        crc_ ^= (byte << 8);
        for (int i = 0; i < 8; ++i) {
            crc_ = (crc_ & 0x8000) ? (crc_ << 1) ^ 0x1021 : (crc_ << 1);
        }
    }

    // Write 4 bytes
    void WriteLong(int32_t val) {
        WriteByte((val >> 24) & 0xFF);
        WriteByte((val >> 16) & 0xFF);
        WriteByte((val >> 8) & 0xFF);
        WriteByte(val & 0xFF);
    }

    void SendCommand(uint8_t address, uint8_t command) {
        WriteByte(address);
        WriteByte(command);
    }

    void WriteChecksum() {
        WriteByte((crc_ >> 8) & 0xFF);
        WriteByte(crc_ & 0xFF);
    }

    void SpeedM1M2(int32_t m1, int32_t m2) {
        crc_ = 0;  // Reset CRC
        SendCommand(RoboclawConfig::MAIN_ADDRESS, RoboclawConfig::CMD_MIXEDSPEED);

        WriteLong(m1);  // Write 4 bytes for M1 speed
        WriteLong(m2);  // Write 4 bytes for M2 speed

        WriteChecksum();  // Send the CRC

        // Wait for the acknowledgement
        uint8_t response;
        read(serial_, buffer(&response, 1));
        if (response != 0xFF) {
            cerr << "Failed to receive ACK for SpeedM1M2 command." << endl;
        }
    }

    void ResetEncoders() {
        SendCommand(RoboclawConfig::MAIN_ADDRESS, RoboclawConfig::CMD_RESETENC);
        WriteChecksum();
    }

private:
    io_service io_service_;
    serial_port serial_;
    uint16_t crc_;
};

class MaxonCtl : public rclcpp::Node {
public:
    MaxonCtl() : Node("maxon_ctl"), roboclaw_() {
        roboclaw_.Open();
        roboclaw_.ResetEncoders();

        // Subscribe to /joy topic
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "/joy", 10, bind(&MaxonCtl::joyCallback, this, _1)
        );
    }

private:
    void joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg) {
        int32_t velM1 = 0;
        int32_t velM2 = 0;

        if (abs(msg->axes[1]) > 0.4) {
            velM1 = 1000;
        }
        if (abs(msg->axes[3]) > 0.4) {
            velM2 = 1000;
        }

        roboclaw_.SpeedM1M2(velM1, velM2);
    }

    Roboclaw roboclaw_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MaxonCtl>());  // Fixed missing semicolon
    rclcpp::shutdown();
    return 0;
}

