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

class Init_DriverVelocity_m2_vel
{
public:
  explicit Init_DriverVelocity_m2_vel(::custom_interfaces::msg::DriverVelocity & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::DriverVelocity m2_vel(::custom_interfaces::msg::DriverVelocity::_m2_vel_type arg)
  {
    msg_.m2_vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::DriverVelocity msg_;
};

class Init_DriverVelocity_m1_vel
{
public:
  Init_DriverVelocity_m1_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriverVelocity_m2_vel m1_vel(::custom_interfaces::msg::DriverVelocity::_m1_vel_type arg)
  {
    msg_.m1_vel = std::move(arg);
    return Init_DriverVelocity_m2_vel(msg_);
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
  return custom_interfaces::msg::builder::Init_DriverVelocity_m1_vel();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__BUILDER_HPP_
