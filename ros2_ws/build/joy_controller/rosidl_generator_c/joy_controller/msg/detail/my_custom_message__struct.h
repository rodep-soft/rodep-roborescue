// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from joy_controller:msg/MyCustomMessage.idl
// generated code does not contain a copyright notice

#ifndef JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__STRUCT_H_
#define JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'my_axes'
// Member 'my_buttons'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MyCustomMessage in the package joy_controller.
/**
  * MyCustomMessage.msg
 */
typedef struct joy_controller__msg__MyCustomMessage
{
  /// Header my_header
  rosidl_runtime_c__float__Sequence my_axes;
  rosidl_runtime_c__int32__Sequence my_buttons;
} joy_controller__msg__MyCustomMessage;

// Struct for a sequence of joy_controller__msg__MyCustomMessage.
typedef struct joy_controller__msg__MyCustomMessage__Sequence
{
  joy_controller__msg__MyCustomMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} joy_controller__msg__MyCustomMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__STRUCT_H_
