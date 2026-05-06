// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vacuum_msgs:msg/TrashItem.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_H_
#define VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_H_

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
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'color'
#include "std_msgs/msg/detail/color_rgba__struct.h"

/// Struct defined in msg/TrashItem in the package vacuum_msgs.
typedef struct vacuum_msgs__msg__TrashItem
{
  uint32_t id;
  rosidl_runtime_c__String type;
  geometry_msgs__msg__Point position;
  float radius;
  std_msgs__msg__ColorRGBA color;
  int32_t score_value;
} vacuum_msgs__msg__TrashItem;

// Struct for a sequence of vacuum_msgs__msg__TrashItem.
typedef struct vacuum_msgs__msg__TrashItem__Sequence
{
  vacuum_msgs__msg__TrashItem * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vacuum_msgs__msg__TrashItem__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_H_
