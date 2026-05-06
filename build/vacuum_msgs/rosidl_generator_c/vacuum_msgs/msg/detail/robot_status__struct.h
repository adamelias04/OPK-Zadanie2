// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vacuum_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define VACUUM_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

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
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/RobotStatus in the package vacuum_msgs.
typedef struct vacuum_msgs__msg__RobotStatus
{
  rosidl_runtime_c__String robot_id;
  geometry_msgs__msg__Pose2D pose;
  geometry_msgs__msg__Twist velocity;
  uint32_t capacity_used;
  uint32_t capacity_max;
  bool in_collision;
} vacuum_msgs__msg__RobotStatus;

// Struct for a sequence of vacuum_msgs__msg__RobotStatus.
typedef struct vacuum_msgs__msg__RobotStatus__Sequence
{
  vacuum_msgs__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vacuum_msgs__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VACUUM_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
