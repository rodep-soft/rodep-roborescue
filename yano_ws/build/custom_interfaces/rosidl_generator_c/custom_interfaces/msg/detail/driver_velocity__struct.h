// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/DriverVelocity.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'flipper_vel'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/DriverVelocity in the package custom_interfaces.
/**
  * DriverVelocity.msg
 */
typedef struct custom_interfaces__msg__DriverVelocity
{
  /// velocity for the left crawler
  float m1_vel;
  /// velocity for the right crawler
  float m2_vel;
  /// velocity for the flippers
  rosidl_runtime_c__int32__Sequence flipper_vel;
} custom_interfaces__msg__DriverVelocity;

// Struct for a sequence of custom_interfaces__msg__DriverVelocity.
typedef struct custom_interfaces__msg__DriverVelocity__Sequence
{
  custom_interfaces__msg__DriverVelocity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__DriverVelocity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__STRUCT_H_
