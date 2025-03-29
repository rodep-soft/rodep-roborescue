// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/SetMode.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_MODE__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/set_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::SetMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::SetMode_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::SetMode_Request>()
{
  return "custom_interfaces::srv::SetMode_Request";
}

template<>
inline const char * name<custom_interfaces::srv::SetMode_Request>()
{
  return "custom_interfaces/srv/SetMode_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::SetMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::SetMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::SetMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::SetMode_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::SetMode_Response>()
{
  return "custom_interfaces::srv::SetMode_Response";
}

template<>
inline const char * name<custom_interfaces::srv::SetMode_Response>()
{
  return "custom_interfaces/srv/SetMode_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::SetMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::SetMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::SetMode>()
{
  return "custom_interfaces::srv::SetMode";
}

template<>
inline const char * name<custom_interfaces::srv::SetMode>()
{
  return "custom_interfaces/srv/SetMode";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetMode>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::SetMode_Request>::value &&
    has_fixed_size<custom_interfaces::srv::SetMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::SetMode>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::SetMode_Request>::value &&
    has_bounded_size<custom_interfaces::srv::SetMode_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::SetMode>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::SetMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::SetMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_MODE__TRAITS_HPP_
