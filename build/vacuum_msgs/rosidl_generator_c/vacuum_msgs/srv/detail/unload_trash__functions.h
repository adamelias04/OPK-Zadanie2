// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vacuum_msgs:srv/UnloadTrash.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__FUNCTIONS_H_
#define VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vacuum_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vacuum_msgs/srv/detail/unload_trash__struct.h"

/// Initialize srv/UnloadTrash message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vacuum_msgs__srv__UnloadTrash_Request
 * )) before or use
 * vacuum_msgs__srv__UnloadTrash_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Request__init(vacuum_msgs__srv__UnloadTrash_Request * msg);

/// Finalize srv/UnloadTrash message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
void
vacuum_msgs__srv__UnloadTrash_Request__fini(vacuum_msgs__srv__UnloadTrash_Request * msg);

/// Create srv/UnloadTrash message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vacuum_msgs__srv__UnloadTrash_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
vacuum_msgs__srv__UnloadTrash_Request *
vacuum_msgs__srv__UnloadTrash_Request__create();

/// Destroy srv/UnloadTrash message.
/**
 * It calls
 * vacuum_msgs__srv__UnloadTrash_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
void
vacuum_msgs__srv__UnloadTrash_Request__destroy(vacuum_msgs__srv__UnloadTrash_Request * msg);

/// Check for srv/UnloadTrash message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Request__are_equal(const vacuum_msgs__srv__UnloadTrash_Request * lhs, const vacuum_msgs__srv__UnloadTrash_Request * rhs);

/// Copy a srv/UnloadTrash message.
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
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Request__copy(
  const vacuum_msgs__srv__UnloadTrash_Request * input,
  vacuum_msgs__srv__UnloadTrash_Request * output);

/// Initialize array of srv/UnloadTrash messages.
/**
 * It allocates the memory for the number of elements and calls
 * vacuum_msgs__srv__UnloadTrash_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Request__Sequence__init(vacuum_msgs__srv__UnloadTrash_Request__Sequence * array, size_t size);

/// Finalize array of srv/UnloadTrash messages.
/**
 * It calls
 * vacuum_msgs__srv__UnloadTrash_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
void
vacuum_msgs__srv__UnloadTrash_Request__Sequence__fini(vacuum_msgs__srv__UnloadTrash_Request__Sequence * array);

/// Create array of srv/UnloadTrash messages.
/**
 * It allocates the memory for the array and calls
 * vacuum_msgs__srv__UnloadTrash_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
vacuum_msgs__srv__UnloadTrash_Request__Sequence *
vacuum_msgs__srv__UnloadTrash_Request__Sequence__create(size_t size);

/// Destroy array of srv/UnloadTrash messages.
/**
 * It calls
 * vacuum_msgs__srv__UnloadTrash_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
void
vacuum_msgs__srv__UnloadTrash_Request__Sequence__destroy(vacuum_msgs__srv__UnloadTrash_Request__Sequence * array);

/// Check for srv/UnloadTrash message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Request__Sequence__are_equal(const vacuum_msgs__srv__UnloadTrash_Request__Sequence * lhs, const vacuum_msgs__srv__UnloadTrash_Request__Sequence * rhs);

/// Copy an array of srv/UnloadTrash messages.
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
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Request__Sequence__copy(
  const vacuum_msgs__srv__UnloadTrash_Request__Sequence * input,
  vacuum_msgs__srv__UnloadTrash_Request__Sequence * output);

/// Initialize srv/UnloadTrash message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vacuum_msgs__srv__UnloadTrash_Response
 * )) before or use
 * vacuum_msgs__srv__UnloadTrash_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Response__init(vacuum_msgs__srv__UnloadTrash_Response * msg);

/// Finalize srv/UnloadTrash message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
void
vacuum_msgs__srv__UnloadTrash_Response__fini(vacuum_msgs__srv__UnloadTrash_Response * msg);

/// Create srv/UnloadTrash message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vacuum_msgs__srv__UnloadTrash_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
vacuum_msgs__srv__UnloadTrash_Response *
vacuum_msgs__srv__UnloadTrash_Response__create();

/// Destroy srv/UnloadTrash message.
/**
 * It calls
 * vacuum_msgs__srv__UnloadTrash_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
void
vacuum_msgs__srv__UnloadTrash_Response__destroy(vacuum_msgs__srv__UnloadTrash_Response * msg);

/// Check for srv/UnloadTrash message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Response__are_equal(const vacuum_msgs__srv__UnloadTrash_Response * lhs, const vacuum_msgs__srv__UnloadTrash_Response * rhs);

/// Copy a srv/UnloadTrash message.
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
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Response__copy(
  const vacuum_msgs__srv__UnloadTrash_Response * input,
  vacuum_msgs__srv__UnloadTrash_Response * output);

/// Initialize array of srv/UnloadTrash messages.
/**
 * It allocates the memory for the number of elements and calls
 * vacuum_msgs__srv__UnloadTrash_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Response__Sequence__init(vacuum_msgs__srv__UnloadTrash_Response__Sequence * array, size_t size);

/// Finalize array of srv/UnloadTrash messages.
/**
 * It calls
 * vacuum_msgs__srv__UnloadTrash_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
void
vacuum_msgs__srv__UnloadTrash_Response__Sequence__fini(vacuum_msgs__srv__UnloadTrash_Response__Sequence * array);

/// Create array of srv/UnloadTrash messages.
/**
 * It allocates the memory for the array and calls
 * vacuum_msgs__srv__UnloadTrash_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
vacuum_msgs__srv__UnloadTrash_Response__Sequence *
vacuum_msgs__srv__UnloadTrash_Response__Sequence__create(size_t size);

/// Destroy array of srv/UnloadTrash messages.
/**
 * It calls
 * vacuum_msgs__srv__UnloadTrash_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
void
vacuum_msgs__srv__UnloadTrash_Response__Sequence__destroy(vacuum_msgs__srv__UnloadTrash_Response__Sequence * array);

/// Check for srv/UnloadTrash message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Response__Sequence__are_equal(const vacuum_msgs__srv__UnloadTrash_Response__Sequence * lhs, const vacuum_msgs__srv__UnloadTrash_Response__Sequence * rhs);

/// Copy an array of srv/UnloadTrash messages.
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
ROSIDL_GENERATOR_C_PUBLIC_vacuum_msgs
bool
vacuum_msgs__srv__UnloadTrash_Response__Sequence__copy(
  const vacuum_msgs__srv__UnloadTrash_Response__Sequence * input,
  vacuum_msgs__srv__UnloadTrash_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__FUNCTIONS_H_
