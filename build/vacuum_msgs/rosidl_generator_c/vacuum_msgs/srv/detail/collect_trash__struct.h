// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vacuum_msgs:srv/CollectTrash.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_H_
#define VACUUM_MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_id'
#include "rosidl_runtime_c/string.h"
// Member 'robot_pos'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/CollectTrash in the package vacuum_msgs.
typedef struct vacuum_msgs__srv__CollectTrash_Request
{
  rosidl_runtime_c__String robot_id;
  geometry_msgs__msg__Point robot_pos;
  float robot_radius;
} vacuum_msgs__srv__CollectTrash_Request;

// Struct for a sequence of vacuum_msgs__srv__CollectTrash_Request.
typedef struct vacuum_msgs__srv__CollectTrash_Request__Sequence
{
  vacuum_msgs__srv__CollectTrash_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vacuum_msgs__srv__CollectTrash_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'collected'
#include "vacuum_msgs/msg/detail/trash_item__struct.h"

/// Struct defined in srv/CollectTrash in the package vacuum_msgs.
typedef struct vacuum_msgs__srv__CollectTrash_Response
{
  bool success;
  vacuum_msgs__msg__TrashItem collected;
  uint32_t capacity_used;
  uint32_t capacity_max;
} vacuum_msgs__srv__CollectTrash_Response;

// Struct for a sequence of vacuum_msgs__srv__CollectTrash_Response.
typedef struct vacuum_msgs__srv__CollectTrash_Response__Sequence
{
  vacuum_msgs__srv__CollectTrash_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vacuum_msgs__srv__CollectTrash_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VACUUM_MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_H_
