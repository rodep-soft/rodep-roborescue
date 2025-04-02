// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_interfaces:msg/DriverVelocity.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_interfaces/msg/detail/driver_velocity__functions.h"
#include "custom_interfaces/msg/detail/driver_velocity__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DriverVelocity_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_interfaces::msg::DriverVelocity(_init);
}

void DriverVelocity_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_interfaces::msg::DriverVelocity *>(message_memory);
  typed_message->~DriverVelocity();
}

size_t size_function__DriverVelocity__flipper_vel(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DriverVelocity__flipper_vel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__DriverVelocity__flipper_vel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__DriverVelocity__flipper_vel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__DriverVelocity__flipper_vel(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__DriverVelocity__flipper_vel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__DriverVelocity__flipper_vel(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__DriverVelocity__flipper_vel(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DriverVelocity_message_member_array[3] = {
  {
    "m1_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces::msg::DriverVelocity, m1_vel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "m2_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces::msg::DriverVelocity, m2_vel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "flipper_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces::msg::DriverVelocity, flipper_vel),  // bytes offset in struct
    nullptr,  // default value
    size_function__DriverVelocity__flipper_vel,  // size() function pointer
    get_const_function__DriverVelocity__flipper_vel,  // get_const(index) function pointer
    get_function__DriverVelocity__flipper_vel,  // get(index) function pointer
    fetch_function__DriverVelocity__flipper_vel,  // fetch(index, &value) function pointer
    assign_function__DriverVelocity__flipper_vel,  // assign(index, value) function pointer
    resize_function__DriverVelocity__flipper_vel  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DriverVelocity_message_members = {
  "custom_interfaces::msg",  // message namespace
  "DriverVelocity",  // message name
  3,  // number of fields
  sizeof(custom_interfaces::msg::DriverVelocity),
  false,  // has_any_key_member_
  DriverVelocity_message_member_array,  // message members
  DriverVelocity_init_function,  // function to initialize message memory (memory has to be allocated)
  DriverVelocity_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DriverVelocity_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DriverVelocity_message_members,
  get_message_typesupport_handle_function,
  &custom_interfaces__msg__DriverVelocity__get_type_hash,
  &custom_interfaces__msg__DriverVelocity__get_type_description,
  &custom_interfaces__msg__DriverVelocity__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_interfaces::msg::DriverVelocity>()
{
  return &::custom_interfaces::msg::rosidl_typesupport_introspection_cpp::DriverVelocity_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_interfaces, msg, DriverVelocity)() {
  return &::custom_interfaces::msg::rosidl_typesupport_introspection_cpp::DriverVelocity_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
