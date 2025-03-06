#include <functional>
#include <algorithm>
#include <memory>
#include <cmath>
#include <string>
#include <chrono>


#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "custom_interfaces/msg/driver_velocity.hpp"

using std::placeholders::_1;

class Operator : public rclcpp::Node
{
  public:
    Operator()
    : Node("operator")
    {
      // Initialize the subscription to joystick inputs
      subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "/joy", 10, std::bind(&Operator::joy_callback, this, _1));
      
      // Initialize the publisher for Twist messages
      // publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

      publisher_ = this->create_publisher<custom_interfaces::msg::DriverVelocity>("/driver", 10);

      // timer_ = this->create_wall_timer(
      //   50ms, std::bind(&Operator::, this));
    }

  private:

  // Constants
    double WIDTH = 0.29;           // [m] Distance between the two crawlers
    double MAX_SPEED = 0.5;       // [m/s] Maximum linear speed
    double MAX_ANGULAR = 0.2;     // Maximum angular speed
    // double m1_joy, m2_joy, linear_x, angular_z;

    // void joy_callback(const sensor_msgs::msg::Joy & msg)
    // {
    //   // Read joystick inputs
    //   m1_joy = msg.axes[1];   // Adjust index if necessary
    //   m2_joy = msg.axes[3];  // Adjust index if necessary

    //   // Calculate linear and angular velocities
    //   linear_x = (m1_joy + m2_joy) * MAX_SPEED / 2; // use average
    //   angular_z = (m2_joy - m1_joy) * MAX_ANGULAR / WIDTH;

    //   // Create and populate the Twist message
    //   auto twist_msg = geometry_msgs::msg::Twist();
    //   twist_msg.linear.x = linear_x;
    //   twist_msg.linear.y = 0.0;
    //   twist_msg.linear.z = 0.0;
    //   twist_msg.angular.x = 0.0;
    //   twist_msg.angular.y = 0.0;
    //   twist_msg.angular.z = angular_z;

    //   // Publish the Twist message
    //   publisher_->publish(twist_msg);

    //   // Optional: Log the values for debugging
    //   RCLCPP_INFO(this->get_logger(), "Linear X: %.2f, Angular Z: %.2f", linear_x, angular_z);
    // }


    // declare variables
    float m1_axis_y = 0;
    float m2_axis_y = 0;

    float m1_vel, m2_vel;

    void joy_callback(const sensor_msgs::msg::Joy& msg) 
    {
      m1_axis_y = std::clamp(msg.axes[1], -0.9f, 0.9f);
      m2_axis_y = std::clamp(msg.axes[3], -0.9f, 0.9f);

      // if (m1_axis_y > 0.9) {
      //   m1_axis_y = 0.9;
      // } else if (m1_axis_y < -0.9) {
      //   m1_axis_y = -0.9;
      // }

      // if (m2_axis_y > 0.9) {
      //   m2_axis_y = 0.9;
      // } else if (m2_axis_y < -0.9) {
      //   m2_axis_y = -0.9;
      // }

      RCLCPP_INFO(this->get_logger(), "values \nm1_axis_y: %f \nm2_axis_y: %f", m1_axis_y, m2_axis_y);

      m1_vel = m1_axis_y * MAX_SPEED;
      m2_vel = m2_axis_y * MAX_SPEED;

      auto message = custom_interfaces::msg::DriverVelocity();

      message.m1_vel = m1_vel;
      message.m2_vel = m2_vel;
      publisher_->publish(message);
    }

    // ROS2 subscription and publisher
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    // rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Publisher<custom_interfaces::msg::DriverVelocity>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Operator>());
  rclcpp::shutdown();
  return 0;
}
