// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:msg/TrashItem.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_H_
#define MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_H_

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

/// Struct defined in msg/TrashItem in the package msgs.
typedef struct msgs__msg__TrashItem
{
  uint32_t id;
  rosidl_runtime_c__String type;
  geometry_msgs__msg__Point position;
  float radius;
  std_msgs__msg__ColorRGBA color;
  int32_t score_value;
} msgs__msg__TrashItem;

// Struct for a sequence of msgs__msg__TrashItem.
typedef struct msgs__msg__TrashItem__Sequence
{
  msgs__msg__TrashItem * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__msg__TrashItem__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_H_
