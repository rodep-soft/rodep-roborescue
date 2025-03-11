#include <functional>
#include <algorithm>
#include <memory>
#include <cmath>
#include <string>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "custom_interfaces/msg/driver_velocity.hpp"
#include "custom_interfaces/srv/set_mode.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class Operator : public rclcpp::Node
{
public:
    enum class Mode { STOP, DRIVE };

    Operator()
        : Node("operator"), m1_vel(0.0f), m2_vel(0.0f), mode_(Mode::STOP)
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "/joy", 10, std::bind(&Operator::joy_callback, this, _1));

        publisher_ = this->create_publisher<custom_interfaces::msg::DriverVelocity>("/driver", 10);
        
        service_ = this->create_service<custom_interfaces::srv::SetMode>(
            "/set_mode", std::bind(&Operator::set_mode_callback, this, _1, _2));
    }

private:
    static constexpr float WIDTH = 0.29f;
    static constexpr float MAX_SPEED = 0.5f;
    static constexpr float DEADZONE = 0.1f;

    float m1_vel, m2_vel;
    Mode mode_;

    static float applyDeadzone(float val, float threshold)
    {
        return (std::abs(val) < threshold) ? 0.0f : val;
    }

    void joy_callback(const sensor_msgs::msg::Joy &msg)
    {
        // ボタンをチェックしてモードを切り替える
        if (msg.buttons.size() > 0)
        {
            // テスト
            if (msg.buttons[4] == 1)  // ボタン0が押された場合
            {
                mode_ = Mode::STOP;
                RCLCPP_INFO(this->get_logger(), "Mode switched to STOP");
            }
            else if (msg.buttons[6] == 1)  // ボタン1が押された場合
            {
                mode_ = Mode::DRIVE;
                RCLCPP_INFO(this->get_logger(), "Mode switched to DRIVE");
            }
        }

        // モードがSTOPの場合は速度を0に設定
        if (mode_ == Mode::STOP)
        {
            m1_vel = 0.0f;
            m2_vel = 0.0f;
        }
        else if (mode_ == Mode::DRIVE)
        {
            if (msg.axes.size() < 4)
            {
                RCLCPP_WARN(this->get_logger(), "Joystick axes array is too small!");
                return;
            }

            float m1_axis_y = applyDeadzone(std::clamp<float>(msg.axes[1], -0.95f, 0.95f), DEADZONE);
            float m2_axis_y = applyDeadzone(std::clamp<float>(msg.axes[3], -0.95f, 0.95f), DEADZONE);

            m1_vel = std::clamp<float>(m1_axis_y * MAX_SPEED, -MAX_SPEED, MAX_SPEED);
            m2_vel = std::clamp<float>(m2_axis_y * MAX_SPEED, -MAX_SPEED, MAX_SPEED);

            //RCLCPP_INFO(this->get_logger(), "%f", m1_vel);
            //RCLCPP_INFO(this->get_logger(), "%f", m2_vel);
        }

        auto message = custom_interfaces::msg::DriverVelocity();
        message.m1_vel = m1_vel;
        message.m2_vel = m2_vel;
        publisher_->publish(message);
    }

    void set_mode_callback(const std::shared_ptr<custom_interfaces::srv::SetMode::Request> request,
                           std::shared_ptr<custom_interfaces::srv::SetMode::Response> response)
    {
        if (request->mode == "STOP")
        {
            mode_ = Mode::STOP;
            response->success = true;
            RCLCPP_INFO(this->get_logger(), "Mode set to STOP");
        }
        else if (request->mode == "DRIVE")
        {
            mode_ = Mode::DRIVE;
            response->success = true;
            RCLCPP_INFO(this->get_logger(), "Mode set to DRIVE");
        }
        else
        {
            response->success = false;
            RCLCPP_WARN(this->get_logger(), "Invalid mode requested");
        }
    }

    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    rclcpp::Publisher<custom_interfaces::msg::DriverVelocity>::SharedPtr publisher_;
    rclcpp::Service<custom_interfaces::srv::SetMode>::SharedPtr service_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Operator>());
    rclcpp::shutdown();
    return 0;
}
