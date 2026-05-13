// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs:msg/TrashCount.idl
// generated code does not contain a copyright notice
#include "msgs/msg/detail/trash_count__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"

bool
msgs__msg__TrashCount__init(msgs__msg__TrashCount * msg)
{
  if (!msg) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    msgs__msg__TrashCount__fini(msg);
    return false;
  }
  // count
  return true;
}

void
msgs__msg__TrashCount__fini(msgs__msg__TrashCount * msg)
{
  if (!msg) {
    return;
  }
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // count
}

bool
msgs__msg__TrashCount__are_equal(const msgs__msg__TrashCount * lhs, const msgs__msg__TrashCount * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  // count
  if (lhs->count != rhs->count) {
    return false;
  }
  return true;
}

bool
msgs__msg__TrashCount__copy(
  const msgs__msg__TrashCount * input,
  msgs__msg__TrashCount * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  // count
  output->count = input->count;
  return true;
}

msgs__msg__TrashCount *
msgs__msg__TrashCount__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrashCount * msg = (msgs__msg__TrashCount *)allocator.allocate(sizeof(msgs__msg__TrashCount), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs__msg__TrashCount));
  bool success = msgs__msg__TrashCount__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs__msg__TrashCount__destroy(msgs__msg__TrashCount * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs__msg__TrashCount__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs__msg__TrashCount__Sequence__init(msgs__msg__TrashCount__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrashCount * data = NULL;

  if (size) {
    data = (msgs__msg__TrashCount *)allocator.zero_allocate(size, sizeof(msgs__msg__TrashCount), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs__msg__TrashCount__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs__msg__TrashCount__fini(&data[i - 1]);
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
msgs__msg__TrashCount__Sequence__fini(msgs__msg__TrashCount__Sequence * array)
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
      msgs__msg__TrashCount__fini(&array->data[i]);
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

msgs__msg__TrashCount__Sequence *
msgs__msg__TrashCount__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrashCount__Sequence * array = (msgs__msg__TrashCount__Sequence *)allocator.allocate(sizeof(msgs__msg__TrashCount__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs__msg__TrashCount__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs__msg__TrashCount__Sequence__destroy(msgs__msg__TrashCount__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs__msg__TrashCount__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs__msg__TrashCount__Sequence__are_equal(const msgs__msg__TrashCount__Sequence * lhs, const msgs__msg__TrashCount__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs__msg__TrashCount__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs__msg__TrashCount__Sequence__copy(
  const msgs__msg__TrashCount__Sequence * input,
  msgs__msg__TrashCount__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs__msg__TrashCount);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs__msg__TrashCount * data =
      (msgs__msg__TrashCount *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs__msg__TrashCount__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs__msg__TrashCount__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs__msg__TrashCount__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
