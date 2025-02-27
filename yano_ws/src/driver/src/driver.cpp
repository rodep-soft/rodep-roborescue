#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std;
using std::placeholders::_1;
using namespace boost::asio;

const double WHEEL_BASE = 0.2;  // Wheel base of the robot

// Function to calculate CRC-16 for Roboclaw
uint16_t calculateCRC(const vector<uint8_t>& data) {
    uint16_t crc = 0;
    for (auto byte : data) {
        crc ^= static_cast<uint16_t>(byte) << 8;
        for (int i = 0; i < 8; i++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ 0x1021;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}

// Function to send a command to the Roboclaw motor driver
void sendRoboclawCommand(const vector<uint8_t>& data) {
    try {
        io_service io;
        serial_port serial(io, "/dev/ttyACM0");  // Use your device path

        // Set serial port options (Adjusted Baud Rate)
        serial.set_option(serial_port_base::baud_rate(38400));
        serial.set_option(serial_port_base::character_size(8));
        serial.set_option(serial_port_base::parity(serial_port_base::parity::none));
        serial.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
        serial.set_option(serial_port_base::flow_control(serial_port_base::flow_control::none));

        // Send data to Roboclaw
        write(serial, buffer(data));

        // Read the response (1 byte)
        uint8_t response;
        read(serial, buffer(&response, 1));

        cout << "Received Response: 0x" << hex << (int)response << endl;
    } catch (boost::system::system_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

// Function to generate motor command based on Twist message
void generateMotorCommand(vector<uint8_t>& data, double speed, double angular, bool is_left_motor) {
    // Add address (example: 0x80 for the Roboclaw address)
    data.push_back(0x80);  // Example address

    // Add command for motor (6 for M1 and 7 for M2)
    data.push_back(is_left_motor ? 0x06 : 0x07);

    // Calculate speed (scale based on Twist message)
    double pre_speed = speed + angular * WHEEL_BASE;
    int motor_speed = static_cast<int>((pre_speed + 0.54) * 127 / 1.08);  // Example conversion
    data.push_back(static_cast<uint8_t>(motor_speed));

    // Calculate CRC and append it to the data
    uint16_t crc = calculateCRC(data);
    data.push_back(static_cast<uint8_t>(crc >> 8));  // High byte
    data.push_back(static_cast<uint8_t>(crc & 0xFF));  // Low byte
}

// Driver class to subscribe to /cmd_vel
class Driver : public rclcpp::Node
{
public:
    Driver()
        : Node("driver")
    {
        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10, std::bind(&Driver::driver_callback, this, _1));
    }

private:
    void driver_callback(const geometry_msgs::msg::Twist& msg) const
    {
        // Log the received command for debugging purposes
        RCLCPP_INFO(this->get_logger(), "Received cmd_vel: linear.x = %.2f, angular.z = %.2f",
                    msg.linear.x, msg.angular.z);

        // Prepare data for the two motors
        vector<uint8_t> left_motor_data;
        vector<uint8_t> right_motor_data;

        // Generate commands for both motors
        generateMotorCommand(left_motor_data, msg.linear.x, msg.angular.z, true);  // Left motor
        generateMotorCommand(right_motor_data, msg.linear.x, msg.angular.z, false); // Right motor

        // Send commands to Roboclaw via serial
        sendRoboclawCommand(left_motor_data);
        sendRoboclawCommand(right_motor_data);
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Driver>());
    rclcpp::shutdown();
    return 0;
}
