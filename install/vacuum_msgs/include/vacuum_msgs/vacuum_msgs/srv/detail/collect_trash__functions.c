// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vacuum_msgs:srv/CollectTrash.idl
// generated code does not contain a copyright notice
#include "vacuum_msgs/srv/detail/collect_trash__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `robot_pos`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
vacuum_msgs__srv__CollectTrash_Request__init(vacuum_msgs__srv__CollectTrash_Request * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    vacuum_msgs__srv__CollectTrash_Request__fini(msg);
    return false;
  }
  // robot_pos
  if (!geometry_msgs__msg__Point__init(&msg->robot_pos)) {
    vacuum_msgs__srv__CollectTrash_Request__fini(msg);
    return false;
  }
  // robot_radius
  return true;
}

void
vacuum_msgs__srv__CollectTrash_Request__fini(vacuum_msgs__srv__CollectTrash_Request * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
  // robot_pos
  geometry_msgs__msg__Point__fini(&msg->robot_pos);
  // robot_radius
}

bool
vacuum_msgs__srv__CollectTrash_Request__are_equal(const vacuum_msgs__srv__CollectTrash_Request * lhs, const vacuum_msgs__srv__CollectTrash_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_id), &(rhs->robot_id)))
  {
    return false;
  }
  // robot_pos
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->robot_pos), &(rhs->robot_pos)))
  {
    return false;
  }
  // robot_radius
  if (lhs->robot_radius != rhs->robot_radius) {
    return false;
  }
  return true;
}

bool
vacuum_msgs__srv__CollectTrash_Request__copy(
  const vacuum_msgs__srv__CollectTrash_Request * input,
  vacuum_msgs__srv__CollectTrash_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_id), &(output->robot_id)))
  {
    return false;
  }
  // robot_pos
  if (!geometry_msgs__msg__Point__copy(
      &(input->robot_pos), &(output->robot_pos)))
  {
    return false;
  }
  // robot_radius
  output->robot_radius = input->robot_radius;
  return true;
}

vacuum_msgs__srv__CollectTrash_Request *
vacuum_msgs__srv__CollectTrash_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__srv__CollectTrash_Request * msg = (vacuum_msgs__srv__CollectTrash_Request *)allocator.allocate(sizeof(vacuum_msgs__srv__CollectTrash_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vacuum_msgs__srv__CollectTrash_Request));
  bool success = vacuum_msgs__srv__CollectTrash_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vacuum_msgs__srv__CollectTrash_Request__destroy(vacuum_msgs__srv__CollectTrash_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vacuum_msgs__srv__CollectTrash_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vacuum_msgs__srv__CollectTrash_Request__Sequence__init(vacuum_msgs__srv__CollectTrash_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__srv__CollectTrash_Request * data = NULL;

  if (size) {
    data = (vacuum_msgs__srv__CollectTrash_Request *)allocator.zero_allocate(size, sizeof(vacuum_msgs__srv__CollectTrash_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vacuum_msgs__srv__CollectTrash_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vacuum_msgs__srv__CollectTrash_Request__fini(&data[i - 1]);
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
vacuum_msgs__srv__CollectTrash_Request__Sequence__fini(vacuum_msgs__srv__CollectTrash_Request__Sequence * array)
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
      vacuum_msgs__srv__CollectTrash_Request__fini(&array->data[i]);
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

vacuum_msgs__srv__CollectTrash_Request__Sequence *
vacuum_msgs__srv__CollectTrash_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__srv__CollectTrash_Request__Sequence * array = (vacuum_msgs__srv__CollectTrash_Request__Sequence *)allocator.allocate(sizeof(vacuum_msgs__srv__CollectTrash_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vacuum_msgs__srv__CollectTrash_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vacuum_msgs__srv__CollectTrash_Request__Sequence__destroy(vacuum_msgs__srv__CollectTrash_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vacuum_msgs__srv__CollectTrash_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vacuum_msgs__srv__CollectTrash_Request__Sequence__are_equal(const vacuum_msgs__srv__CollectTrash_Request__Sequence * lhs, const vacuum_msgs__srv__CollectTrash_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vacuum_msgs__srv__CollectTrash_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vacuum_msgs__srv__CollectTrash_Request__Sequence__copy(
  const vacuum_msgs__srv__CollectTrash_Request__Sequence * input,
  vacuum_msgs__srv__CollectTrash_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vacuum_msgs__srv__CollectTrash_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vacuum_msgs__srv__CollectTrash_Request * data =
      (vacuum_msgs__srv__CollectTrash_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vacuum_msgs__srv__CollectTrash_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vacuum_msgs__srv__CollectTrash_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vacuum_msgs__srv__CollectTrash_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `collected`
#include "vacuum_msgs/msg/detail/trash_item__functions.h"

bool
vacuum_msgs__srv__CollectTrash_Response__init(vacuum_msgs__srv__CollectTrash_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // collected
  if (!vacuum_msgs__msg__TrashItem__init(&msg->collected)) {
    vacuum_msgs__srv__CollectTrash_Response__fini(msg);
    return false;
  }
  // capacity_used
  // capacity_max
  return true;
}

void
vacuum_msgs__srv__CollectTrash_Response__fini(vacuum_msgs__srv__CollectTrash_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // collected
  vacuum_msgs__msg__TrashItem__fini(&msg->collected);
  // capacity_used
  // capacity_max
}

bool
vacuum_msgs__srv__CollectTrash_Response__are_equal(const vacuum_msgs__srv__CollectTrash_Response * lhs, const vacuum_msgs__srv__CollectTrash_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // collected
  if (!vacuum_msgs__msg__TrashItem__are_equal(
      &(lhs->collected), &(rhs->collected)))
  {
    return false;
  }
  // capacity_used
  if (lhs->capacity_used != rhs->capacity_used) {
    return false;
  }
  // capacity_max
  if (lhs->capacity_max != rhs->capacity_max) {
    return false;
  }
  return true;
}

bool
vacuum_msgs__srv__CollectTrash_Response__copy(
  const vacuum_msgs__srv__CollectTrash_Response * input,
  vacuum_msgs__srv__CollectTrash_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // collected
  if (!vacuum_msgs__msg__TrashItem__copy(
      &(input->collected), &(output->collected)))
  {
    return false;
  }
  // capacity_used
  output->capacity_used = input->capacity_used;
  // capacity_max
  output->capacity_max = input->capacity_max;
  return true;
}

vacuum_msgs__srv__CollectTrash_Response *
vacuum_msgs__srv__CollectTrash_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__srv__CollectTrash_Response * msg = (vacuum_msgs__srv__CollectTrash_Response *)allocator.allocate(sizeof(vacuum_msgs__srv__CollectTrash_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vacuum_msgs__srv__CollectTrash_Response));
  bool success = vacuum_msgs__srv__CollectTrash_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vacuum_msgs__srv__CollectTrash_Response__destroy(vacuum_msgs__srv__CollectTrash_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vacuum_msgs__srv__CollectTrash_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vacuum_msgs__srv__CollectTrash_Response__Sequence__init(vacuum_msgs__srv__CollectTrash_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__srv__CollectTrash_Response * data = NULL;

  if (size) {
    data = (vacuum_msgs__srv__CollectTrash_Response *)allocator.zero_allocate(size, sizeof(vacuum_msgs__srv__CollectTrash_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vacuum_msgs__srv__CollectTrash_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vacuum_msgs__srv__CollectTrash_Response__fini(&data[i - 1]);
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
vacuum_msgs__srv__CollectTrash_Response__Sequence__fini(vacuum_msgs__srv__CollectTrash_Response__Sequence * array)
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
      vacuum_msgs__srv__CollectTrash_Response__fini(&array->data[i]);
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

vacuum_msgs__srv__CollectTrash_Response__Sequence *
vacuum_msgs__srv__CollectTrash_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vacuum_msgs__srv__CollectTrash_Response__Sequence * array = (vacuum_msgs__srv__CollectTrash_Response__Sequence *)allocator.allocate(sizeof(vacuum_msgs__srv__CollectTrash_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vacuum_msgs__srv__CollectTrash_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vacuum_msgs__srv__CollectTrash_Response__Sequence__destroy(vacuum_msgs__srv__CollectTrash_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vacuum_msgs__srv__CollectTrash_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vacuum_msgs__srv__CollectTrash_Response__Sequence__are_equal(const vacuum_msgs__srv__CollectTrash_Response__Sequence * lhs, const vacuum_msgs__srv__CollectTrash_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vacuum_msgs__srv__CollectTrash_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vacuum_msgs__srv__CollectTrash_Response__Sequence__copy(
  const vacuum_msgs__srv__CollectTrash_Response__Sequence * input,
  vacuum_msgs__srv__CollectTrash_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vacuum_msgs__srv__CollectTrash_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vacuum_msgs__srv__CollectTrash_Response * data =
      (vacuum_msgs__srv__CollectTrash_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vacuum_msgs__srv__CollectTrash_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vacuum_msgs__srv__CollectTrash_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vacuum_msgs__srv__CollectTrash_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
