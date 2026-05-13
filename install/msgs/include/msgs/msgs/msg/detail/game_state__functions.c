// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs:msg/GameState.idl
// generated code does not contain a copyright notice
#include "msgs/msg/detail/game_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `mode`
// Member `phase`
// Member `winner`
#include "rosidl_runtime_c/string_functions.h"
// Member `collected`
#include "msgs/msg/detail/trash_count__functions.h"
// Member `active_trash`
#include "msgs/msg/detail/trash_item__functions.h"
// Member `robots`
#include "msgs/msg/detail/robot_status__functions.h"

bool
msgs__msg__GameState__init(msgs__msg__GameState * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    msgs__msg__GameState__fini(msg);
    return false;
  }
  // phase
  if (!rosidl_runtime_c__String__init(&msg->phase)) {
    msgs__msg__GameState__fini(msg);
    return false;
  }
  // elapsed_seconds
  // score
  // collected
  if (!msgs__msg__TrashCount__Sequence__init(&msg->collected, 0)) {
    msgs__msg__GameState__fini(msg);
    return false;
  }
  // active_trash
  if (!msgs__msg__TrashItem__Sequence__init(&msg->active_trash, 0)) {
    msgs__msg__GameState__fini(msg);
    return false;
  }
  // robots
  if (!msgs__msg__RobotStatus__Sequence__init(&msg->robots, 0)) {
    msgs__msg__GameState__fini(msg);
    return false;
  }
  // winner
  if (!rosidl_runtime_c__String__init(&msg->winner)) {
    msgs__msg__GameState__fini(msg);
    return false;
  }
  return true;
}

void
msgs__msg__GameState__fini(msgs__msg__GameState * msg)
{
  if (!msg) {
    return;
  }
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // phase
  rosidl_runtime_c__String__fini(&msg->phase);
  // elapsed_seconds
  // score
  // collected
  msgs__msg__TrashCount__Sequence__fini(&msg->collected);
  // active_trash
  msgs__msg__TrashItem__Sequence__fini(&msg->active_trash);
  // robots
  msgs__msg__RobotStatus__Sequence__fini(&msg->robots);
  // winner
  rosidl_runtime_c__String__fini(&msg->winner);
}

bool
msgs__msg__GameState__are_equal(const msgs__msg__GameState * lhs, const msgs__msg__GameState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  // phase
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->phase), &(rhs->phase)))
  {
    return false;
  }
  // elapsed_seconds
  if (lhs->elapsed_seconds != rhs->elapsed_seconds) {
    return false;
  }
  // score
  if (lhs->score != rhs->score) {
    return false;
  }
  // collected
  if (!msgs__msg__TrashCount__Sequence__are_equal(
      &(lhs->collected), &(rhs->collected)))
  {
    return false;
  }
  // active_trash
  if (!msgs__msg__TrashItem__Sequence__are_equal(
      &(lhs->active_trash), &(rhs->active_trash)))
  {
    return false;
  }
  // robots
  if (!msgs__msg__RobotStatus__Sequence__are_equal(
      &(lhs->robots), &(rhs->robots)))
  {
    return false;
  }
  // winner
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->winner), &(rhs->winner)))
  {
    return false;
  }
  return true;
}

bool
msgs__msg__GameState__copy(
  const msgs__msg__GameState * input,
  msgs__msg__GameState * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  // phase
  if (!rosidl_runtime_c__String__copy(
      &(input->phase), &(output->phase)))
  {
    return false;
  }
  // elapsed_seconds
  output->elapsed_seconds = input->elapsed_seconds;
  // score
  output->score = input->score;
  // collected
  if (!msgs__msg__TrashCount__Sequence__copy(
      &(input->collected), &(output->collected)))
  {
    return false;
  }
  // active_trash
  if (!msgs__msg__TrashItem__Sequence__copy(
      &(input->active_trash), &(output->active_trash)))
  {
    return false;
  }
  // robots
  if (!msgs__msg__RobotStatus__Sequence__copy(
      &(input->robots), &(output->robots)))
  {
    return false;
  }
  // winner
  if (!rosidl_runtime_c__String__copy(
      &(input->winner), &(output->winner)))
  {
    return false;
  }
  return true;
}

msgs__msg__GameState *
msgs__msg__GameState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__GameState * msg = (msgs__msg__GameState *)allocator.allocate(sizeof(msgs__msg__GameState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs__msg__GameState));
  bool success = msgs__msg__GameState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs__msg__GameState__destroy(msgs__msg__GameState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs__msg__GameState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs__msg__GameState__Sequence__init(msgs__msg__GameState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__GameState * data = NULL;

  if (size) {
    data = (msgs__msg__GameState *)allocator.zero_allocate(size, sizeof(msgs__msg__GameState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs__msg__GameState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs__msg__GameState__fini(&data[i - 1]);
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
msgs__msg__GameState__Sequence__fini(msgs__msg__GameState__Sequence * array)
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
      msgs__msg__GameState__fini(&array->data[i]);
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

msgs__msg__GameState__Sequence *
msgs__msg__GameState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__GameState__Sequence * array = (msgs__msg__GameState__Sequence *)allocator.allocate(sizeof(msgs__msg__GameState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs__msg__GameState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs__msg__GameState__Sequence__destroy(msgs__msg__GameState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs__msg__GameState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs__msg__GameState__Sequence__are_equal(const msgs__msg__GameState__Sequence * lhs, const msgs__msg__GameState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs__msg__GameState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs__msg__GameState__Sequence__copy(
  const msgs__msg__GameState__Sequence * input,
  msgs__msg__GameState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs__msg__GameState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs__msg__GameState * data =
      (msgs__msg__GameState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs__msg__GameState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs__msg__GameState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs__msg__GameState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
