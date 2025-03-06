#include <functional>
#include <algorithm>
#include <memory>
#include <cmath>
#include <string>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "custom_interfaces/msg/driver_velocity.hpp"

using std::placeholders::_1;

class Operator : public rclcpp::Node
{
public:
    Operator()
        : Node("operator"), m1_vel(0.0f), m2_vel(0.0f)
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "/joy", 10, std::bind(&Operator::joy_callback, this, _1));
        
        publisher_ = this->create_publisher<custom_interfaces::msg::DriverVelocity>("/driver", 10);
    }

private:
    static constexpr float WIDTH = 0.29f;        // [m] Distance between the two crawlers
    static constexpr float MAX_SPEED = 0.5f;     // [m/s] Maximum linear speed
    static constexpr float DEADZONE = 0.1f;      // Deadzone threshold

    float m1_vel, m2_vel;

    static float applyDeadzone(float val, float threshold) {
        return (std::abs(val) < threshold) ? 0.0f : val;
    }

    void joy_callback(const sensor_msgs::msg::Joy &msg)
    {
        if (msg.axes.size() < 4)
        {
            RCLCPP_WARN(this->get_logger(), "Joystick axes array is too small!");
            return;
        }

        float m1_axis_y = applyDeadzone(std::clamp<float>(msg.axes[1], -0.95f, 0.95f), DEADZONE);
        float m2_axis_y = applyDeadzone(std::clamp<float>(msg.axes[3], -0.95f, 0.95f), DEADZONE);

        RCLCPP_INFO(this->get_logger(), "values \nm1_axis_y: %.2f \nm2_axis_y: %.2f", m1_axis_y, m2_axis_y);

        m1_vel = std::clamp<float>(m1_axis_y * MAX_SPEED, -MAX_SPEED, MAX_SPEED);
        m2_vel = std::clamp<float>(m2_axis_y * MAX_SPEED, -MAX_SPEED, MAX_SPEED);

        auto message = custom_interfaces::msg::DriverVelocity();
        message.m1_vel = m1_vel;
        message.m2_vel = m2_vel;
        publisher_->publish(message);
    }

    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    rclcpp::Publisher<custom_interfaces::msg::DriverVelocity>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Operator>());
    rclcpp::shutdown();
    return 0;
}
