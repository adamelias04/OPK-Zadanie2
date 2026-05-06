// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vacuum_msgs:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__GAME_STATE__STRUCT_H_
#define VACUUM_MSGS__MSG__DETAIL__GAME_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mode'
// Member 'phase'
// Member 'winner'
#include "rosidl_runtime_c/string.h"
// Member 'collected'
#include "vacuum_msgs/msg/detail/trash_count__struct.h"
// Member 'active_trash'
#include "vacuum_msgs/msg/detail/trash_item__struct.h"
// Member 'robots'
#include "vacuum_msgs/msg/detail/robot_status__struct.h"

/// Struct defined in msg/GameState in the package vacuum_msgs.
typedef struct vacuum_msgs__msg__GameState
{
  rosidl_runtime_c__String mode;
  rosidl_runtime_c__String phase;
  float elapsed_seconds;
  int32_t score;
  vacuum_msgs__msg__TrashCount__Sequence collected;
  vacuum_msgs__msg__TrashItem__Sequence active_trash;
  vacuum_msgs__msg__RobotStatus__Sequence robots;
  rosidl_runtime_c__String winner;
} vacuum_msgs__msg__GameState;

// Struct for a sequence of vacuum_msgs__msg__GameState.
typedef struct vacuum_msgs__msg__GameState__Sequence
{
  vacuum_msgs__msg__GameState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vacuum_msgs__msg__GameState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VACUUM_MSGS__MSG__DETAIL__GAME_STATE__STRUCT_H_
