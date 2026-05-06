// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vacuum_msgs:msg/GameState.idl
// generated code does not contain a copyright notice
#include "vacuum_msgs/msg/detail/game_state__functions.h"

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
#include "vacuum_msgs/msg/detail/trash_count__functions.h"
// Member `active_trash`
#include "vacuum_msgs/msg/detail/trash_item__functions.h"
// Member `robots`
#include "vacuum_msgs/msg/detail/robot_status__functions.h"

bool
vacuum_msgs__msg__GameState__init(vacuum_msgs__msg__GameState * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    vacuum_msgs__msg__GameState__fini(msg);
    return false;
  }
  // phase
  if (!rosidl_runtime_c__String__init(&msg->phase)) {
    vacuum_msgs__msg__GameState__fini(msg);
    return false;
  }
  // elapsed_seconds
  // score
  // collected
  if (!vacuum_msgs__msg__TrashCount__Sequence__init(&msg->collected, 0)) {
    vacuum_msgs__msg__GameState__fini(msg);
    return false;
  }
  // active_trash
  if (!vacuum_msgs__msg__TrashItem__Sequence__init(&msg->active_trash, 0)) {
    vacuum_msgs__msg__GameState__fini(msg);
    return false;
  }
  // robots
  if (!vacuum_msgs__msg__RobotStatus__Sequence__init(&msg->robots, 0)) {
    vacuum_msgs__msg__GameState__fini(msg);
    return false;
  }
  // winner
  if (!rosidl_runtime_c__String__init(&msg->winner)) {
    vacuum_msgs__msg__GameState__fini(msg);
    return false;
  }
  return true;
}

void
vacuum_msgs__msg__GameState__fini(vacuum_msgs__msg__GameState * msg)
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
  vacuum_msgs__msg__TrashCount__Sequence__fini(&msg->collected);
  // active_trash
  vacuum_msgs__msg__TrashItem__Sequence__fini(&msg->active_trash);
  // robots
  vacuum_msgs__msg__RobotStatus__Sequence__fini(&msg->robots);
  // winner
  rosidl_runtime_c__String__fini(&msg->winner);
}

bool
vacuum_msgs__msg__GameState__are_equal(const vacuum_msgs__msg__GameState * lhs, const vacuum_msgs__msg__GameState * rhs)
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
  if (!vacuum_msgs__msg__TrashCount__Sequence__are_equal(
      &(lhs->collected), &(rhs->collected)))
  {
    return false;
  }
  // active_trash
  if (!vacuum_msgs__msg__TrashItem__Sequence__are_equal(
      &(lhs->active_trash), &(rhs->active_trash)))
  {
    return false;
  }
  // robots
  if (!vacuum_msgs__msg__RobotStatus__Sequence__are_equal(
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
vacuum_msgs__msg__GameState__copy(
  const vacuum_msgs__msg__GameState * input,
  vacuum_msgs__msg__GameState * output)
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
  if (!vacuum_msgs__msg__TrashCount__Sequence__copy(
      &(input->collected), &(output->collected)))
  {
    return false;
  }
  // active_trash
  if (!vacuum_msgs__msg__TrashItem__Sequence__copy(
      &(input->active_trash), &(output->active_trash)))
  {
    return false;
  }
  // robots
  if (!vacuum_msgs__msg__RobotStatus__Sequence__copy(
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

vacuum_msgs__msg__GameState *
vacuum_msgs__msg__GameState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__msg__GameState * msg = (vacuum_msgs__msg__GameState *)allocator.allocate(sizeof(vacuum_msgs__msg__GameState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vacuum_msgs__msg__GameState));
  bool success = vacuum_msgs__msg__GameState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vacuum_msgs__msg__GameState__destroy(vacuum_msgs__msg__GameState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vacuum_msgs__msg__GameState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vacuum_msgs__msg__GameState__Sequence__init(vacuum_msgs__msg__GameState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__msg__GameState * data = NULL;

  if (size) {
    data = (vacuum_msgs__msg__GameState *)allocator.zero_allocate(size, sizeof(vacuum_msgs__msg__GameState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vacuum_msgs__msg__GameState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vacuum_msgs__msg__GameState__fini(&data[i - 1]);
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
vacuum_msgs__msg__GameState__Sequence__fini(vacuum_msgs__msg__GameState__Sequence * array)
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
      vacuum_msgs__msg__GameState__fini(&array->data[i]);
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

vacuum_msgs__msg__GameState__Sequence *
vacuum_msgs__msg__GameState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__msg__GameState__Sequence * array = (vacuum_msgs__msg__GameState__Sequence *)allocator.allocate(sizeof(vacuum_msgs__msg__GameState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vacuum_msgs__msg__GameState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vacuum_msgs__msg__GameState__Sequence__destroy(vacuum_msgs__msg__GameState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vacuum_msgs__msg__GameState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vacuum_msgs__msg__GameState__Sequence__are_equal(const vacuum_msgs__msg__GameState__Sequence * lhs, const vacuum_msgs__msg__GameState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vacuum_msgs__msg__GameState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vacuum_msgs__msg__GameState__Sequence__copy(
  const vacuum_msgs__msg__GameState__Sequence * input,
  vacuum_msgs__msg__GameState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vacuum_msgs__msg__GameState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vacuum_msgs__msg__GameState * data =
      (vacuum_msgs__msg__GameState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vacuum_msgs__msg__GameState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vacuum_msgs__msg__GameState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vacuum_msgs__msg__GameState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
