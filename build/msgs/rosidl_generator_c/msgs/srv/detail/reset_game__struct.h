// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:srv/ResetGame.idl
// generated code does not contain a copyright notice

#ifndef MSGS__SRV__DETAIL__RESET_GAME__STRUCT_H_
#define MSGS__SRV__DETAIL__RESET_GAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ResetGame in the package msgs.
typedef struct msgs__srv__ResetGame_Request
{
  uint8_t structure_needs_at_least_one_member;
} msgs__srv__ResetGame_Request;

// Struct for a sequence of msgs__srv__ResetGame_Request.
typedef struct msgs__srv__ResetGame_Request__Sequence
{
  msgs__srv__ResetGame_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__srv__ResetGame_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ResetGame in the package msgs.
typedef struct msgs__srv__ResetGame_Response
{
  bool success;
} msgs__srv__ResetGame_Response;

// Struct for a sequence of msgs__srv__ResetGame_Response.
typedef struct msgs__srv__ResetGame_Response__Sequence
{
  msgs__srv__ResetGame_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__srv__ResetGame_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__SRV__DETAIL__RESET_GAME__STRUCT_H_
