#include <iostream>
#include "dynamixel_sdk/dynamixel_sdk.h"
#include <rclcpp/rclcpp.hpp>

// Control table address for Dynamixel motors
#define ADDR_MX_TORQUE_ENABLE     24
#define ADDR_MX_GOAL_POSITION     30
#define ADDR_MX_PRESENT_POSITION  36

// Protocol version
#define PROTOCOL_VERSION 1.0

// Dynamixel ID
#define DXL_ID 1

// Port/baudrate settings
#define DEVICE_NAME "/dev/ttyUSB0" // Change to the appropriate port
#define BAUDRATE    57600

// Error check and print functions
int dxl_comm_result = COMM_TX_FAIL;

// Dynamixel SDK objects
dynamixel::PortHandler *portHandler;
dynamixel::PacketHandler *packetHandler;

// Check if the connection is valid
bool checkConnection()
{
    // Open port
    portHandler = dynamixel::PortHandler::getPortHandler(DEVICE_NAME);
    packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

    if (portHandler->openPort()) {
        std::cout << "Succeeded to open the port!" << std::endl;
    } else {
        std::cerr << "Failed to open the port!" << std::endl;
        return false;
    }

    if (portHandler->setBaudRate(BAUDRATE)) {
        std::cout << "Succeeded to set the baudrate!" << std::endl;
    } else {
        std::cerr << "Failed to set the baudrate!" << std::endl;
        return false;
    }

    // Ping the motor to check if it's connected
    uint8_t dxl_error = 0;
    uint16_t dxl_model_number = 0;

    dxl_comm_result = packetHandler->ping(portHandler, DXL_ID, &dxl_model_number, &dxl_error);
    if (dxl_comm_result == COMM_SUCCESS) {
        std::cout << "Dynamixel motor is connected!" << std::endl;
        return true;
    } else {
        std::cerr << "Dynamixel motor not connected!" << std::endl;
        return false;
    }
}

int main(int argc, char **argv)
{
    // Initialize ROS 2 node (you can add ROS 2 functionality here)
    rclcpp::init(argc, argv);

    if (checkConnection()) {
        std::cout << "Motor is connected and ready!" << std::endl;
    } else {
        std::cerr << "Motor connection failed." << std::endl;
    }

    rclcpp::shutdown();
    return 0;
}
