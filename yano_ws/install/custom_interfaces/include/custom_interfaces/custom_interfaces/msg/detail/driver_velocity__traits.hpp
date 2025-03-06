// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/DriverVelocity.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/driver_velocity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DriverVelocity & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_vel
  {
    out << "left_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.left_vel, out);
    out << ", ";
  }

  // member: right_vel
  {
    out << "right_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.right_vel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DriverVelocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.left_vel, out);
    out << "\n";
  }

  // member: right_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.right_vel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DriverVelocity & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::DriverVelocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::DriverVelocity & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::DriverVelocity>()
{
  return "custom_interfaces::msg::DriverVelocity";
}

template<>
inline const char * name<custom_interfaces::msg::DriverVelocity>()
{
  return "custom_interfaces/msg/DriverVelocity";
}

template<>
struct has_fixed_size<custom_interfaces::msg::DriverVelocity>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::msg::DriverVelocity>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::msg::DriverVelocity>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__TRAITS_HPP_
