// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs:srv/ResetGame.idl
// generated code does not contain a copyright notice
#include "msgs/srv/detail/reset_game__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
msgs__srv__ResetGame_Request__init(msgs__srv__ResetGame_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
msgs__srv__ResetGame_Request__fini(msgs__srv__ResetGame_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
msgs__srv__ResetGame_Request__are_equal(const msgs__srv__ResetGame_Request * lhs, const msgs__srv__ResetGame_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
msgs__srv__ResetGame_Request__copy(
  const msgs__srv__ResetGame_Request * input,
  msgs__srv__ResetGame_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

msgs__srv__ResetGame_Request *
msgs__srv__ResetGame_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__srv__ResetGame_Request * msg = (msgs__srv__ResetGame_Request *)allocator.allocate(sizeof(msgs__srv__ResetGame_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs__srv__ResetGame_Request));
  bool success = msgs__srv__ResetGame_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs__srv__ResetGame_Request__destroy(msgs__srv__ResetGame_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs__srv__ResetGame_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs__srv__ResetGame_Request__Sequence__init(msgs__srv__ResetGame_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__srv__ResetGame_Request * data = NULL;

  if (size) {
    data = (msgs__srv__ResetGame_Request *)allocator.zero_allocate(size, sizeof(msgs__srv__ResetGame_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs__srv__ResetGame_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs__srv__ResetGame_Request__fini(&data[i - 1]);
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
msgs__srv__ResetGame_Request__Sequence__fini(msgs__srv__ResetGame_Request__Sequence * array)
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
      msgs__srv__ResetGame_Request__fini(&array->data[i]);
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

msgs__srv__ResetGame_Request__Sequence *
msgs__srv__ResetGame_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__srv__ResetGame_Request__Sequence * array = (msgs__srv__ResetGame_Request__Sequence *)allocator.allocate(sizeof(msgs__srv__ResetGame_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs__srv__ResetGame_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs__srv__ResetGame_Request__Sequence__destroy(msgs__srv__ResetGame_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs__srv__ResetGame_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs__srv__ResetGame_Request__Sequence__are_equal(const msgs__srv__ResetGame_Request__Sequence * lhs, const msgs__srv__ResetGame_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs__srv__ResetGame_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs__srv__ResetGame_Request__Sequence__copy(
  const msgs__srv__ResetGame_Request__Sequence * input,
  msgs__srv__ResetGame_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs__srv__ResetGame_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs__srv__ResetGame_Request * data =
      (msgs__srv__ResetGame_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs__srv__ResetGame_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs__srv__ResetGame_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs__srv__ResetGame_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
msgs__srv__ResetGame_Response__init(msgs__srv__ResetGame_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
msgs__srv__ResetGame_Response__fini(msgs__srv__ResetGame_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
msgs__srv__ResetGame_Response__are_equal(const msgs__srv__ResetGame_Response * lhs, const msgs__srv__ResetGame_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
msgs__srv__ResetGame_Response__copy(
  const msgs__srv__ResetGame_Response * input,
  msgs__srv__ResetGame_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

msgs__srv__ResetGame_Response *
msgs__srv__ResetGame_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__srv__ResetGame_Response * msg = (msgs__srv__ResetGame_Response *)allocator.allocate(sizeof(msgs__srv__ResetGame_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs__srv__ResetGame_Response));
  bool success = msgs__srv__ResetGame_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs__srv__ResetGame_Response__destroy(msgs__srv__ResetGame_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs__srv__ResetGame_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs__srv__ResetGame_Response__Sequence__init(msgs__srv__ResetGame_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__srv__ResetGame_Response * data = NULL;

  if (size) {
    data = (msgs__srv__ResetGame_Response *)allocator.zero_allocate(size, sizeof(msgs__srv__ResetGame_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs__srv__ResetGame_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs__srv__ResetGame_Response__fini(&data[i - 1]);
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
msgs__srv__ResetGame_Response__Sequence__fini(msgs__srv__ResetGame_Response__Sequence * array)
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
      msgs__srv__ResetGame_Response__fini(&array->data[i]);
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

msgs__srv__ResetGame_Response__Sequence *
msgs__srv__ResetGame_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__srv__ResetGame_Response__Sequence * array = (msgs__srv__ResetGame_Response__Sequence *)allocator.allocate(sizeof(msgs__srv__ResetGame_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs__srv__ResetGame_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs__srv__ResetGame_Response__Sequence__destroy(msgs__srv__ResetGame_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs__srv__ResetGame_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs__srv__ResetGame_Response__Sequence__are_equal(const msgs__srv__ResetGame_Response__Sequence * lhs, const msgs__srv__ResetGame_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs__srv__ResetGame_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs__srv__ResetGame_Response__Sequence__copy(
  const msgs__srv__ResetGame_Response__Sequence * input,
  msgs__srv__ResetGame_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs__srv__ResetGame_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs__srv__ResetGame_Response * data =
      (msgs__srv__ResetGame_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs__srv__ResetGame_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs__srv__ResetGame_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs__srv__ResetGame_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
