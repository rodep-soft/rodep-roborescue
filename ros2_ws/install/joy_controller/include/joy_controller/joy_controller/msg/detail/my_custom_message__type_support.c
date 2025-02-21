// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from joy_controller:msg/MyCustomMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "joy_controller/msg/detail/my_custom_message__rosidl_typesupport_introspection_c.h"
#include "joy_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "joy_controller/msg/detail/my_custom_message__functions.h"
#include "joy_controller/msg/detail/my_custom_message__struct.h"


// Include directives for member types
// Member `my_axes`
// Member `my_buttons`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  joy_controller__msg__MyCustomMessage__init(message_memory);
}

void joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_fini_function(void * message_memory)
{
  joy_controller__msg__MyCustomMessage__fini(message_memory);
}

size_t joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__size_function__MyCustomMessage__my_axes(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_const_function__MyCustomMessage__my_axes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_function__MyCustomMessage__my_axes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__fetch_function__MyCustomMessage__my_axes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_const_function__MyCustomMessage__my_axes(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__assign_function__MyCustomMessage__my_axes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_function__MyCustomMessage__my_axes(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__resize_function__MyCustomMessage__my_axes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__size_function__MyCustomMessage__my_buttons(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_const_function__MyCustomMessage__my_buttons(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_function__MyCustomMessage__my_buttons(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__fetch_function__MyCustomMessage__my_buttons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_const_function__MyCustomMessage__my_buttons(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__assign_function__MyCustomMessage__my_buttons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_function__MyCustomMessage__my_buttons(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__resize_function__MyCustomMessage__my_buttons(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_message_member_array[2] = {
  {
    "my_axes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(joy_controller__msg__MyCustomMessage, my_axes),  // bytes offset in struct
    NULL,  // default value
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__size_function__MyCustomMessage__my_axes,  // size() function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_const_function__MyCustomMessage__my_axes,  // get_const(index) function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_function__MyCustomMessage__my_axes,  // get(index) function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__fetch_function__MyCustomMessage__my_axes,  // fetch(index, &value) function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__assign_function__MyCustomMessage__my_axes,  // assign(index, value) function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__resize_function__MyCustomMessage__my_axes  // resize(index) function pointer
  },
  {
    "my_buttons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(joy_controller__msg__MyCustomMessage, my_buttons),  // bytes offset in struct
    NULL,  // default value
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__size_function__MyCustomMessage__my_buttons,  // size() function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_const_function__MyCustomMessage__my_buttons,  // get_const(index) function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__get_function__MyCustomMessage__my_buttons,  // get(index) function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__fetch_function__MyCustomMessage__my_buttons,  // fetch(index, &value) function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__assign_function__MyCustomMessage__my_buttons,  // assign(index, value) function pointer
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__resize_function__MyCustomMessage__my_buttons  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_message_members = {
  "joy_controller__msg",  // message namespace
  "MyCustomMessage",  // message name
  2,  // number of fields
  sizeof(joy_controller__msg__MyCustomMessage),
  joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_message_member_array,  // message members
  joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_message_type_support_handle = {
  0,
  &joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_joy_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, joy_controller, msg, MyCustomMessage)() {
  if (!joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_message_type_support_handle.typesupport_identifier) {
    joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &joy_controller__msg__MyCustomMessage__rosidl_typesupport_introspection_c__MyCustomMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
