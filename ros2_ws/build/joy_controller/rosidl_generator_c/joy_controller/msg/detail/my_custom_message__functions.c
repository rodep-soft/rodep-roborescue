// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from joy_controller:msg/MyCustomMessage.idl
// generated code does not contain a copyright notice
#include "joy_controller/msg/detail/my_custom_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `my_axes`
// Member `my_buttons`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
joy_controller__msg__MyCustomMessage__init(joy_controller__msg__MyCustomMessage * msg)
{
  if (!msg) {
    return false;
  }
  // my_axes
  if (!rosidl_runtime_c__float__Sequence__init(&msg->my_axes, 0)) {
    joy_controller__msg__MyCustomMessage__fini(msg);
    return false;
  }
  // my_buttons
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->my_buttons, 0)) {
    joy_controller__msg__MyCustomMessage__fini(msg);
    return false;
  }
  return true;
}

void
joy_controller__msg__MyCustomMessage__fini(joy_controller__msg__MyCustomMessage * msg)
{
  if (!msg) {
    return;
  }
  // my_axes
  rosidl_runtime_c__float__Sequence__fini(&msg->my_axes);
  // my_buttons
  rosidl_runtime_c__int32__Sequence__fini(&msg->my_buttons);
}

bool
joy_controller__msg__MyCustomMessage__are_equal(const joy_controller__msg__MyCustomMessage * lhs, const joy_controller__msg__MyCustomMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // my_axes
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->my_axes), &(rhs->my_axes)))
  {
    return false;
  }
  // my_buttons
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->my_buttons), &(rhs->my_buttons)))
  {
    return false;
  }
  return true;
}

bool
joy_controller__msg__MyCustomMessage__copy(
  const joy_controller__msg__MyCustomMessage * input,
  joy_controller__msg__MyCustomMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // my_axes
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->my_axes), &(output->my_axes)))
  {
    return false;
  }
  // my_buttons
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->my_buttons), &(output->my_buttons)))
  {
    return false;
  }
  return true;
}

joy_controller__msg__MyCustomMessage *
joy_controller__msg__MyCustomMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  joy_controller__msg__MyCustomMessage * msg = (joy_controller__msg__MyCustomMessage *)allocator.allocate(sizeof(joy_controller__msg__MyCustomMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(joy_controller__msg__MyCustomMessage));
  bool success = joy_controller__msg__MyCustomMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
joy_controller__msg__MyCustomMessage__destroy(joy_controller__msg__MyCustomMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    joy_controller__msg__MyCustomMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
joy_controller__msg__MyCustomMessage__Sequence__init(joy_controller__msg__MyCustomMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  joy_controller__msg__MyCustomMessage * data = NULL;

  if (size) {
    data = (joy_controller__msg__MyCustomMessage *)allocator.zero_allocate(size, sizeof(joy_controller__msg__MyCustomMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = joy_controller__msg__MyCustomMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        joy_controller__msg__MyCustomMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
joy_controller__msg__MyCustomMessage__Sequence__fini(joy_controller__msg__MyCustomMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      joy_controller__msg__MyCustomMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

joy_controller__msg__MyCustomMessage__Sequence *
joy_controller__msg__MyCustomMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  joy_controller__msg__MyCustomMessage__Sequence * array = (joy_controller__msg__MyCustomMessage__Sequence *)allocator.allocate(sizeof(joy_controller__msg__MyCustomMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = joy_controller__msg__MyCustomMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
joy_controller__msg__MyCustomMessage__Sequence__destroy(joy_controller__msg__MyCustomMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    joy_controller__msg__MyCustomMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
joy_controller__msg__MyCustomMessage__Sequence__are_equal(const joy_controller__msg__MyCustomMessage__Sequence * lhs, const joy_controller__msg__MyCustomMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!joy_controller__msg__MyCustomMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
joy_controller__msg__MyCustomMessage__Sequence__copy(
  const joy_controller__msg__MyCustomMessage__Sequence * input,
  joy_controller__msg__MyCustomMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(joy_controller__msg__MyCustomMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    joy_controller__msg__MyCustomMessage * data =
      (joy_controller__msg__MyCustomMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!joy_controller__msg__MyCustomMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          joy_controller__msg__MyCustomMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!joy_controller__msg__MyCustomMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
