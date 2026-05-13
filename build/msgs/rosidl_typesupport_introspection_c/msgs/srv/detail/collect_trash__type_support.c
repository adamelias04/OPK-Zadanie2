// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msgs:srv/CollectTrash.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msgs/srv/detail/collect_trash__rosidl_typesupport_introspection_c.h"
#include "msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msgs/srv/detail/collect_trash__functions.h"
#include "msgs/srv/detail/collect_trash__struct.h"


// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `robot_pos`
#include "geometry_msgs/msg/point.h"
// Member `robot_pos`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs__srv__CollectTrash_Request__init(message_memory);
}

void msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_fini_function(void * message_memory)
{
  msgs__srv__CollectTrash_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_member_array[3] = {
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__srv__CollectTrash_Request, robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__srv__CollectTrash_Request, robot_pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__srv__CollectTrash_Request, robot_radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_members = {
  "msgs__srv",  // message namespace
  "CollectTrash_Request",  // message name
  3,  // number of fields
  sizeof(msgs__srv__CollectTrash_Request),
  msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_member_array,  // message members
  msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_type_support_handle = {
  0,
  &msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, srv, CollectTrash_Request)() {
  msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_type_support_handle.typesupport_identifier) {
    msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs__srv__CollectTrash_Request__rosidl_typesupport_introspection_c__CollectTrash_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "msgs/srv/detail/collect_trash__rosidl_typesupport_introspection_c.h"
// already included above
// #include "msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "msgs/srv/detail/collect_trash__functions.h"
// already included above
// #include "msgs/srv/detail/collect_trash__struct.h"


// Include directives for member types
// Member `collected`
#include "msgs/msg/trash_item.h"
// Member `collected`
#include "msgs/msg/detail/trash_item__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs__srv__CollectTrash_Response__init(message_memory);
}

void msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_fini_function(void * message_memory)
{
  msgs__srv__CollectTrash_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_member_array[4] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__srv__CollectTrash_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "collected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__srv__CollectTrash_Response, collected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "capacity_used",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__srv__CollectTrash_Response, capacity_used),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "capacity_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__srv__CollectTrash_Response, capacity_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_members = {
  "msgs__srv",  // message namespace
  "CollectTrash_Response",  // message name
  4,  // number of fields
  sizeof(msgs__srv__CollectTrash_Response),
  msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_member_array,  // message members
  msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_type_support_handle = {
  0,
  &msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, srv, CollectTrash_Response)() {
  msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, msg, TrashItem)();
  if (!msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_type_support_handle.typesupport_identifier) {
    msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs__srv__CollectTrash_Response__rosidl_typesupport_introspection_c__CollectTrash_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "msgs/srv/detail/collect_trash__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_service_members = {
  "msgs__srv",  // service namespace
  "CollectTrash",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_Request_message_type_support_handle,
  NULL  // response message
  // msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_Response_message_type_support_handle
};

static rosidl_service_type_support_t msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_service_type_support_handle = {
  0,
  &msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, srv, CollectTrash_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, srv, CollectTrash_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, srv, CollectTrash)() {
  if (!msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_service_type_support_handle.typesupport_identifier) {
    msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, srv, CollectTrash_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, srv, CollectTrash_Response)()->data;
  }

  return &msgs__srv__detail__collect_trash__rosidl_typesupport_introspection_c__CollectTrash_service_type_support_handle;
}
