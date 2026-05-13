// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:srv/CollectTrash.idl
// generated code does not contain a copyright notice

#ifndef MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_H_
#define MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_H_

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

/// Struct defined in srv/CollectTrash in the package msgs.
typedef struct msgs__srv__CollectTrash_Request
{
  rosidl_runtime_c__String robot_id;
  geometry_msgs__msg__Point robot_pos;
  float robot_radius;
} msgs__srv__CollectTrash_Request;

// Struct for a sequence of msgs__srv__CollectTrash_Request.
typedef struct msgs__srv__CollectTrash_Request__Sequence
{
  msgs__srv__CollectTrash_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__srv__CollectTrash_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'collected'
#include "msgs/msg/detail/trash_item__struct.h"

/// Struct defined in srv/CollectTrash in the package msgs.
typedef struct msgs__srv__CollectTrash_Response
{
  bool success;
  msgs__msg__TrashItem collected;
  uint32_t capacity_used;
  uint32_t capacity_max;
} msgs__srv__CollectTrash_Response;

// Struct for a sequence of msgs__srv__CollectTrash_Response.
typedef struct msgs__srv__CollectTrash_Response__Sequence
{
  msgs__srv__CollectTrash_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__srv__CollectTrash_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_H_
