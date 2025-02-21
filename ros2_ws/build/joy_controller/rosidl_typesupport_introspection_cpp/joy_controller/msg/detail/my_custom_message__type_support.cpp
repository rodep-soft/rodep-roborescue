// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from joy_controller:msg/MyCustomMessage.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "joy_controller/msg/detail/my_custom_message__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace joy_controller
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MyCustomMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) joy_controller::msg::MyCustomMessage(_init);
}

void MyCustomMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<joy_controller::msg::MyCustomMessage *>(message_memory);
  typed_message->~MyCustomMessage();
}

size_t size_function__MyCustomMessage__my_axes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyCustomMessage__my_axes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MyCustomMessage__my_axes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__MyCustomMessage__my_axes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MyCustomMessage__my_axes(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MyCustomMessage__my_axes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MyCustomMessage__my_axes(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__MyCustomMessage__my_axes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MyCustomMessage__my_buttons(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyCustomMessage__my_buttons(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__MyCustomMessage__my_buttons(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__MyCustomMessage__my_buttons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__MyCustomMessage__my_buttons(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__MyCustomMessage__my_buttons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__MyCustomMessage__my_buttons(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__MyCustomMessage__my_buttons(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MyCustomMessage_message_member_array[2] = {
  {
    "my_axes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(joy_controller::msg::MyCustomMessage, my_axes),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyCustomMessage__my_axes,  // size() function pointer
    get_const_function__MyCustomMessage__my_axes,  // get_const(index) function pointer
    get_function__MyCustomMessage__my_axes,  // get(index) function pointer
    fetch_function__MyCustomMessage__my_axes,  // fetch(index, &value) function pointer
    assign_function__MyCustomMessage__my_axes,  // assign(index, value) function pointer
    resize_function__MyCustomMessage__my_axes  // resize(index) function pointer
  },
  {
    "my_buttons",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(joy_controller::msg::MyCustomMessage, my_buttons),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyCustomMessage__my_buttons,  // size() function pointer
    get_const_function__MyCustomMessage__my_buttons,  // get_const(index) function pointer
    get_function__MyCustomMessage__my_buttons,  // get(index) function pointer
    fetch_function__MyCustomMessage__my_buttons,  // fetch(index, &value) function pointer
    assign_function__MyCustomMessage__my_buttons,  // assign(index, value) function pointer
    resize_function__MyCustomMessage__my_buttons  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MyCustomMessage_message_members = {
  "joy_controller::msg",  // message namespace
  "MyCustomMessage",  // message name
  2,  // number of fields
  sizeof(joy_controller::msg::MyCustomMessage),
  MyCustomMessage_message_member_array,  // message members
  MyCustomMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  MyCustomMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MyCustomMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MyCustomMessage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace joy_controller


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<joy_controller::msg::MyCustomMessage>()
{
  return &::joy_controller::msg::rosidl_typesupport_introspection_cpp::MyCustomMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, joy_controller, msg, MyCustomMessage)() {
  return &::joy_controller::msg::rosidl_typesupport_introspection_cpp::MyCustomMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
