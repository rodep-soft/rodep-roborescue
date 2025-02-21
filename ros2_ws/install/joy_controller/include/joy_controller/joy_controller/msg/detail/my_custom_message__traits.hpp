// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from joy_controller:msg/MyCustomMessage.idl
// generated code does not contain a copyright notice

#ifndef JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__TRAITS_HPP_
#define JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "joy_controller/msg/detail/my_custom_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace joy_controller
{

namespace msg
{

inline void to_flow_style_yaml(
  const MyCustomMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: my_axes
  {
    if (msg.my_axes.size() == 0) {
      out << "my_axes: []";
    } else {
      out << "my_axes: [";
      size_t pending_items = msg.my_axes.size();
      for (auto item : msg.my_axes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: my_buttons
  {
    if (msg.my_buttons.size() == 0) {
      out << "my_buttons: []";
    } else {
      out << "my_buttons: [";
      size_t pending_items = msg.my_buttons.size();
      for (auto item : msg.my_buttons) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyCustomMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: my_axes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.my_axes.size() == 0) {
      out << "my_axes: []\n";
    } else {
      out << "my_axes:\n";
      for (auto item : msg.my_axes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: my_buttons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.my_buttons.size() == 0) {
      out << "my_buttons: []\n";
    } else {
      out << "my_buttons:\n";
      for (auto item : msg.my_buttons) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyCustomMessage & msg, bool use_flow_style = false)
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

}  // namespace joy_controller

namespace rosidl_generator_traits
{

[[deprecated("use joy_controller::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const joy_controller::msg::MyCustomMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  joy_controller::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use joy_controller::msg::to_yaml() instead")]]
inline std::string to_yaml(const joy_controller::msg::MyCustomMessage & msg)
{
  return joy_controller::msg::to_yaml(msg);
}

template<>
inline const char * data_type<joy_controller::msg::MyCustomMessage>()
{
  return "joy_controller::msg::MyCustomMessage";
}

template<>
inline const char * name<joy_controller::msg::MyCustomMessage>()
{
  return "joy_controller/msg/MyCustomMessage";
}

template<>
struct has_fixed_size<joy_controller::msg::MyCustomMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<joy_controller::msg::MyCustomMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<joy_controller::msg::MyCustomMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__TRAITS_HPP_
