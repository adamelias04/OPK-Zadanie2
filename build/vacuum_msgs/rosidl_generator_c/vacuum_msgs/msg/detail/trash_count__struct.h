// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vacuum_msgs:msg/TrashCount.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_H_
#define VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_H_

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

/// Struct defined in msg/TrashCount in the package vacuum_msgs.
typedef struct vacuum_msgs__msg__TrashCount
{
  rosidl_runtime_c__String type;
  uint32_t count;
} vacuum_msgs__msg__TrashCount;

// Struct for a sequence of vacuum_msgs__msg__TrashCount.
typedef struct vacuum_msgs__msg__TrashCount__Sequence
{
  vacuum_msgs__msg__TrashCount * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vacuum_msgs__msg__TrashCount__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_H_
