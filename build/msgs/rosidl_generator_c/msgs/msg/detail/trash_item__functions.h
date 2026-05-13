// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from msgs:msg/TrashItem.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRASH_ITEM__FUNCTIONS_H_
#define MSGS__MSG__DETAIL__TRASH_ITEM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "msgs/msg/rosidl_generator_c__visibility_control.h"

#include "msgs/msg/detail/trash_item__struct.h"

/// Initialize msg/TrashItem message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * msgs__msg__TrashItem
 * )) before or use
 * msgs__msg__TrashItem__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
bool
msgs__msg__TrashItem__init(msgs__msg__TrashItem * msg);

/// Finalize msg/TrashItem message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
void
msgs__msg__TrashItem__fini(msgs__msg__TrashItem * msg);

/// Create msg/TrashItem message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * msgs__msg__TrashItem__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
msgs__msg__TrashItem *
msgs__msg__TrashItem__create();

/// Destroy msg/TrashItem message.
/**
 * It calls
 * msgs__msg__TrashItem__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
void
msgs__msg__TrashItem__destroy(msgs__msg__TrashItem * msg);

/// Check for msg/TrashItem message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
bool
msgs__msg__TrashItem__are_equal(const msgs__msg__TrashItem * lhs, const msgs__msg__TrashItem * rhs);

/// Copy a msg/TrashItem message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
bool
msgs__msg__TrashItem__copy(
  const msgs__msg__TrashItem * input,
  msgs__msg__TrashItem * output);

/// Initialize array of msg/TrashItem messages.
/**
 * It allocates the memory for the number of elements and calls
 * msgs__msg__TrashItem__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
bool
msgs__msg__TrashItem__Sequence__init(msgs__msg__TrashItem__Sequence * array, size_t size);

/// Finalize array of msg/TrashItem messages.
/**
 * It calls
 * msgs__msg__TrashItem__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
void
msgs__msg__TrashItem__Sequence__fini(msgs__msg__TrashItem__Sequence * array);

/// Create array of msg/TrashItem messages.
/**
 * It allocates the memory for the array and calls
 * msgs__msg__TrashItem__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
msgs__msg__TrashItem__Sequence *
msgs__msg__TrashItem__Sequence__create(size_t size);

/// Destroy array of msg/TrashItem messages.
/**
 * It calls
 * msgs__msg__TrashItem__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
void
msgs__msg__TrashItem__Sequence__destroy(msgs__msg__TrashItem__Sequence * array);

/// Check for msg/TrashItem message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
bool
msgs__msg__TrashItem__Sequence__are_equal(const msgs__msg__TrashItem__Sequence * lhs, const msgs__msg__TrashItem__Sequence * rhs);

/// Copy an array of msg/TrashItem messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs
bool
msgs__msg__TrashItem__Sequence__copy(
  const msgs__msg__TrashItem__Sequence * input,
  msgs__msg__TrashItem__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__TRASH_ITEM__FUNCTIONS_H_
