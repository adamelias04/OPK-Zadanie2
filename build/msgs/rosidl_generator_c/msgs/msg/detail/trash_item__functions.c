// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs:msg/TrashItem.idl
// generated code does not contain a copyright notice
#include "msgs/msg/detail/trash_item__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `color`
#include "std_msgs/msg/detail/color_rgba__functions.h"

bool
msgs__msg__TrashItem__init(msgs__msg__TrashItem * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    msgs__msg__TrashItem__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    msgs__msg__TrashItem__fini(msg);
    return false;
  }
  // radius
  // color
  if (!std_msgs__msg__ColorRGBA__init(&msg->color)) {
    msgs__msg__TrashItem__fini(msg);
    return false;
  }
  // score_value
  return true;
}

void
msgs__msg__TrashItem__fini(msgs__msg__TrashItem * msg)
{
  if (!msg) {
    return;
  }
  // id
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // radius
  // color
  std_msgs__msg__ColorRGBA__fini(&msg->color);
  // score_value
}

bool
msgs__msg__TrashItem__are_equal(const msgs__msg__TrashItem * lhs, const msgs__msg__TrashItem * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  // color
  if (!std_msgs__msg__ColorRGBA__are_equal(
      &(lhs->color), &(rhs->color)))
  {
    return false;
  }
  // score_value
  if (lhs->score_value != rhs->score_value) {
    return false;
  }
  return true;
}

bool
msgs__msg__TrashItem__copy(
  const msgs__msg__TrashItem * input,
  msgs__msg__TrashItem * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // radius
  output->radius = input->radius;
  // color
  if (!std_msgs__msg__ColorRGBA__copy(
      &(input->color), &(output->color)))
  {
    return false;
  }
  // score_value
  output->score_value = input->score_value;
  return true;
}

msgs__msg__TrashItem *
msgs__msg__TrashItem__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrashItem * msg = (msgs__msg__TrashItem *)allocator.allocate(sizeof(msgs__msg__TrashItem), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs__msg__TrashItem));
  bool success = msgs__msg__TrashItem__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs__msg__TrashItem__destroy(msgs__msg__TrashItem * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs__msg__TrashItem__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs__msg__TrashItem__Sequence__init(msgs__msg__TrashItem__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrashItem * data = NULL;

  if (size) {
    data = (msgs__msg__TrashItem *)allocator.zero_allocate(size, sizeof(msgs__msg__TrashItem), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs__msg__TrashItem__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs__msg__TrashItem__fini(&data[i - 1]);
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
msgs__msg__TrashItem__Sequence__fini(msgs__msg__TrashItem__Sequence * array)
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
      msgs__msg__TrashItem__fini(&array->data[i]);
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

msgs__msg__TrashItem__Sequence *
msgs__msg__TrashItem__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrashItem__Sequence * array = (msgs__msg__TrashItem__Sequence *)allocator.allocate(sizeof(msgs__msg__TrashItem__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs__msg__TrashItem__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs__msg__TrashItem__Sequence__destroy(msgs__msg__TrashItem__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs__msg__TrashItem__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs__msg__TrashItem__Sequence__are_equal(const msgs__msg__TrashItem__Sequence * lhs, const msgs__msg__TrashItem__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs__msg__TrashItem__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs__msg__TrashItem__Sequence__copy(
  const msgs__msg__TrashItem__Sequence * input,
  msgs__msg__TrashItem__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs__msg__TrashItem);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs__msg__TrashItem * data =
      (msgs__msg__TrashItem *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs__msg__TrashItem__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs__msg__TrashItem__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs__msg__TrashItem__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
