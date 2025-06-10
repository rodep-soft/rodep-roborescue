#include <functional>
#include <memory>
#include <cmath>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "geometry_msgs/msg/twist.hpp"

using std::placeholders::_1;

// Constants
const double WIDTH = 0.29;           // [m] Distance between the two crawlers
const double MAX_SPEED = 0.5;       // [m/s] Maximum linear speed
const double MAX_ANGULAR = 0.2;     // Maximum angular speed

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
      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    }

  private:
    double left_joy, right_joy, linear_x, angular_z;

    void joy_callback(const sensor_msgs::msg::Joy & msg)
    {
      // Read joystick inputs
      left_joy = msg.axes[1];   // Adjust index if necessary
      right_joy = msg.axes[3];  // Adjust index if necessary

      // Calculate linear and angular velocities
      linear_x = (left_joy + right_joy) * MAX_SPEED / 2; // use average
      angular_z = (right_joy - left_joy) * MAX_ANGULAR / WIDTH;

      // Create and populate the Twist message
      auto twist_msg = geometry_msgs::msg::Twist();
      twist_msg.linear.x = linear_x;
      twist_msg.linear.y = 0.0;
      twist_msg.linear.z = 0.0;
      twist_msg.angular.x = 0.0;
      twist_msg.angular.y = 0.0;
      twist_msg.angular.z = angular_z;

      // Publish the Twist message
      publisher_->publish(twist_msg);

      // Optional: Log the values for debugging
      RCLCPP_INFO(this->get_logger(), "Linear X: %.2f, Angular Z: %.2f", linear_x, angular_z);
    }

    // ROS2 subscription and publisher
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Operator>());
  rclcpp::shutdown();
  return 0;
}

