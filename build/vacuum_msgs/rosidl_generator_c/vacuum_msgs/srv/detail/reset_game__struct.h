// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vacuum_msgs:srv/ResetGame.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__RESET_GAME__STRUCT_H_
#define VACUUM_MSGS__SRV__DETAIL__RESET_GAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ResetGame in the package vacuum_msgs.
typedef struct vacuum_msgs__srv__ResetGame_Request
{
  uint8_t structure_needs_at_least_one_member;
} vacuum_msgs__srv__ResetGame_Request;

// Struct for a sequence of vacuum_msgs__srv__ResetGame_Request.
typedef struct vacuum_msgs__srv__ResetGame_Request__Sequence
{
  vacuum_msgs__srv__ResetGame_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vacuum_msgs__srv__ResetGame_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ResetGame in the package vacuum_msgs.
typedef struct vacuum_msgs__srv__ResetGame_Response
{
  bool success;
} vacuum_msgs__srv__ResetGame_Response;

// Struct for a sequence of vacuum_msgs__srv__ResetGame_Response.
typedef struct vacuum_msgs__srv__ResetGame_Response__Sequence
{
  vacuum_msgs__srv__ResetGame_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vacuum_msgs__srv__ResetGame_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VACUUM_MSGS__SRV__DETAIL__RESET_GAME__STRUCT_H_
