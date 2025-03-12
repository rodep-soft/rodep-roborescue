#include <rclcpp/rclcpp.hpp>
#include <custom_interfaces/msg/driver_velocity.hpp>
#include <std_msgs/msg/bool.hpp>
#include <memory>
#include <functional>
#include <vector>
#include "dynamixel_workbench_toolbox/dynamixel_workbench.h"

using std::placeholders::_1;

class FlipperDriver : public rclcpp::Node {
public:
    FlipperDriver() : Node("flipper_driver") {
        declare_parameter("port_name", "/dev/ttyUSB0");
        declare_parameter("baud_rate", 115200);
        declare_parameter("dynamixel_ids", std::vector<int>({1, 2, 3, 4}));
        // declare_parameter("protocol_version", 2.0);

        initParams();

        if (!initDynamixel()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to initialize Dynamixel Workbench");
            rclcpp::shutdown();
        }

        subscription_ = this->create_subscription<custom_interfaces::msg::DriverVelocity>(
            "/flipper_driver", 10, std::bind(&FlipperDriver::driver_callback, this, _1));

        estop_subscription_ = this->create_subscription<std_msgs::msg::Bool>(
            "/emergency_stop", 10, std::bind(&FlipperDriver::estop_callback, this, _1));

        // status_publisher_ = this->create_publisher<custom_interfaces::msg::DriverVelocity>("/flipper_status", 10);

        // timer_ = this->create_wall_timer(
        // std::chrono::seconds(1), std::bind(&FlipperDriver::publish_status, this));
    }

private:
    DynamixelWorkbench dxl_wb_;
    std::string port_name_;
    int baud_rate_;
    std::vector<long int> dynamixel_ids_;
    bool estop_active_ = false;
    // double protocol_version_;

    rclcpp::Subscription<custom_interfaces::msg::DriverVelocity>::SharedPtr subscription_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr estop_subscription_;
    // rclcpp::Publisher<custom_interfaces::msg::DriverVelocity>::SharedPtr status_publisher_;
    // rclcpp::TimerBase::SharedPtr timer_;

    void initParams() {
        port_name_ = get_parameter("port_name").as_string();
        baud_rate_ = get_parameter("baud_rate").as_int();
        dynamixel_ids_ = get_parameter("dynamixel_ids").as_integer_array();
        // protocol_version_ = get_parameter("protocol_version").as_double();
    }

    bool initDynamixel() {
        if (!dxl_wb_.init(port_name_.c_str(), baud_rate_)) {
            RCLCPP_ERROR(this->get_logger(), "Failed to initialize Dynamixel Workbench");
            return false;
        }

        for (const auto& id : dynamixel_ids_) {
            if (!dxl_wb_.ping(id)) {
                RCLCPP_ERROR(this->get_logger(), "Failed to ping Dynamixel motor with ID %ld", id);
                return false;
            }

            dxl_wb_.wheelMode(id, 0);  // Set to wheel mode
            dxl_wb_.itemWrite(id, "Velocity_Limit", 1023);  // Set velocity limit
        }

        RCLCPP_INFO(this->get_logger(), "Dynamixel Workbench initialized successfully");
        return true;
    }

    void driver_callback(const custom_interfaces::msg::DriverVelocity &msg) {
        if (estop_active_) {
            RCLCPP_WARN(this->get_logger(), "Emergency stop is active. Ignoring velocity commands.");
            return;
        }

        std::vector<int32_t> velocities = {
            msg.flipper_vel[0],
            msg.flipper_vel[1],
            msg.flipper_vel[2],
            msg.flipper_vel[3]
        };

        for (size_t i = 0; i < dynamixel_ids_.size(); ++i) {
            if (!dxl_wb_.goalVelocity(dynamixel_ids_[i], velocities[i])) {
                RCLCPP_ERROR(this->get_logger(), "Failed to set goal velocity for Dynamixel motor with ID %ld", dynamixel_ids_[i]);
            } else {
                RCLCPP_INFO(this->get_logger(), "Set goal velocity to %d for Dynamixel motor with ID %ld", velocities[i], dynamixel_ids_[i]);
            }
        }
    }

    void estop_callback(const std_msgs::msg::Bool::SharedPtr msg) {
        estop_active_ = msg->data;

        if (estop_active_) {
            RCLCPP_WARN(this->get_logger(), "Emergency stop activated. Stopping all motors.");
            stopMotors();
        } else {
            RCLCPP_INFO(this->get_logger(), "Emergency stop deactivated. Resuming motor control.");
        }
    }

    void stopMotors() {
        for (const auto& id : dynamixel_ids_) {
            dxl_wb_.goalVelocity(id, 0);
        }
    }

    // void publish_status() {
    //     auto message = custom_interfaces::msg::DriverVelocity();
    //     for (size_t i = 0; i < dynamixel_ids_.size(); ++i) {
    //         int32_t velocity = 0;
    //         dxl_wb_.itemRead(dynamixel_ids_[i], "Present_Velocity", &velocity);
    //         message.flipper[i] = velocity;
    //     }
    //     status_publisher_->publish(message);
    // }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FlipperDriver>());
    rclcpp::shutdown();
    return 0;
}
