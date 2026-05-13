// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__GAME_STATE__STRUCT_H_
#define MSGS__MSG__DETAIL__GAME_STATE__STRUCT_H_

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
#include "msgs/msg/detail/trash_count__struct.h"
// Member 'active_trash'
#include "msgs/msg/detail/trash_item__struct.h"
// Member 'robots'
#include "msgs/msg/detail/robot_status__struct.h"

/// Struct defined in msg/GameState in the package msgs.
typedef struct msgs__msg__GameState
{
  rosidl_runtime_c__String mode;
  rosidl_runtime_c__String phase;
  float elapsed_seconds;
  int32_t score;
  msgs__msg__TrashCount__Sequence collected;
  msgs__msg__TrashItem__Sequence active_trash;
  msgs__msg__RobotStatus__Sequence robots;
  rosidl_runtime_c__String winner;
} msgs__msg__GameState;

// Struct for a sequence of msgs__msg__GameState.
typedef struct msgs__msg__GameState__Sequence
{
  msgs__msg__GameState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__msg__GameState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__GAME_STATE__STRUCT_H_
