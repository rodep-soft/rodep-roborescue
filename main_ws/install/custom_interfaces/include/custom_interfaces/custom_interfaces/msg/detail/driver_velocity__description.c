// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/DriverVelocity.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/driver_velocity__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__DriverVelocity__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9e, 0x0b, 0x16, 0x82, 0x8b, 0xfa, 0x61, 0x4d,
      0x04, 0xd4, 0x03, 0x0e, 0x23, 0x36, 0xc9, 0xa4,
      0x83, 0xe2, 0x26, 0x52, 0xbe, 0x44, 0xd5, 0xee,
      0x0e, 0xbb, 0x36, 0xa7, 0x29, 0x13, 0xde, 0xbb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__DriverVelocity__TYPE_NAME[] = "custom_interfaces/msg/DriverVelocity";

// Define type names, field names, and default values
static char custom_interfaces__msg__DriverVelocity__FIELD_NAME__m1_vel[] = "m1_vel";
static char custom_interfaces__msg__DriverVelocity__FIELD_NAME__m2_vel[] = "m2_vel";
static char custom_interfaces__msg__DriverVelocity__FIELD_NAME__flipper_vel[] = "flipper_vel";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__DriverVelocity__FIELDS[] = {
  {
    {custom_interfaces__msg__DriverVelocity__FIELD_NAME__m1_vel, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__DriverVelocity__FIELD_NAME__m2_vel, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__DriverVelocity__FIELD_NAME__flipper_vel, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__msg__DriverVelocity__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__DriverVelocity__TYPE_NAME, 36, 36},
      {custom_interfaces__msg__DriverVelocity__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# DriverVelocity.msg\n"
  "\n"
  "float32 m1_vel # velocity for the left crawler\n"
  "float32 m2_vel # velocity for the right crawler\n"
  "\n"
  "int32[] flipper_vel # velocity for the flippers";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__DriverVelocity__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__DriverVelocity__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 166, 166},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__DriverVelocity__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__DriverVelocity__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
