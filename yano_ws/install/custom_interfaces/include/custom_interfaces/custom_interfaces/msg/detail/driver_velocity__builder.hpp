// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/DriverVelocity.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/driver_velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_DriverVelocity_right_vel
{
public:
  explicit Init_DriverVelocity_right_vel(::custom_interfaces::msg::DriverVelocity & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::DriverVelocity right_vel(::custom_interfaces::msg::DriverVelocity::_right_vel_type arg)
  {
    msg_.right_vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::DriverVelocity msg_;
};

class Init_DriverVelocity_left_vel
{
public:
  Init_DriverVelocity_left_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriverVelocity_right_vel left_vel(::custom_interfaces::msg::DriverVelocity::_left_vel_type arg)
  {
    msg_.left_vel = std::move(arg);
    return Init_DriverVelocity_right_vel(msg_);
  }

private:
  ::custom_interfaces::msg::DriverVelocity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::DriverVelocity>()
{
  return custom_interfaces::msg::builder::Init_DriverVelocity_left_vel();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__BUILDER_HPP_
