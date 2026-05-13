// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:msg/TrashCount.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_H_
#define MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TrashCount in the package msgs.
typedef struct msgs__msg__TrashCount
{
  rosidl_runtime_c__String type;
  uint32_t count;
} msgs__msg__TrashCount;

// Struct for a sequence of msgs__msg__TrashCount.
typedef struct msgs__msg__TrashCount__Sequence
{
  msgs__msg__TrashCount * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__msg__TrashCount__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_H_
