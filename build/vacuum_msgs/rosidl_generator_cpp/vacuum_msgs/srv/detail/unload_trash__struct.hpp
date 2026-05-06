// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vacuum_msgs:srv/UnloadTrash.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__STRUCT_HPP_
#define VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'robot_pos'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vacuum_msgs__srv__UnloadTrash_Request __attribute__((deprecated))
#else
# define DEPRECATED__vacuum_msgs__srv__UnloadTrash_Request __declspec(deprecated)
#endif

namespace vacuum_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UnloadTrash_Request_
{
  using Type = UnloadTrash_Request_<ContainerAllocator>;

  explicit UnloadTrash_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
    }
  }

  explicit UnloadTrash_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc),
    robot_pos(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
    }
  }

  // field types and members
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _robot_pos_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _robot_pos_type robot_pos;

  // setters for named parameter idiom
  Type & set__robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__robot_pos(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->robot_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vacuum_msgs__srv__UnloadTrash_Request
    std::shared_ptr<vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vacuum_msgs__srv__UnloadTrash_Request
    std::shared_ptr<vacuum_msgs::srv::UnloadTrash_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UnloadTrash_Request_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->robot_pos != other.robot_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const UnloadTrash_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UnloadTrash_Request_

// alias to use template instance with default allocator
using UnloadTrash_Request =
  vacuum_msgs::srv::UnloadTrash_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vacuum_msgs


#ifndef _WIN32
# define DEPRECATED__vacuum_msgs__srv__UnloadTrash_Response __attribute__((deprecated))
#else
# define DEPRECATED__vacuum_msgs__srv__UnloadTrash_Response __declspec(deprecated)
#endif

namespace vacuum_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UnloadTrash_Response_
{
  using Type = UnloadTrash_Response_<ContainerAllocator>;

  explicit UnloadTrash_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->score_gained = 0l;
      this->capacity_used = 0ul;
    }
  }

  explicit UnloadTrash_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->score_gained = 0l;
      this->capacity_used = 0ul;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _score_gained_type =
    int32_t;
  _score_gained_type score_gained;
  using _capacity_used_type =
    uint32_t;
  _capacity_used_type capacity_used;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__score_gained(
    const int32_t & _arg)
  {
    this->score_gained = _arg;
    return *this;
  }
  Type & set__capacity_used(
    const uint32_t & _arg)
  {
    this->capacity_used = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vacuum_msgs__srv__UnloadTrash_Response
    std::shared_ptr<vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vacuum_msgs__srv__UnloadTrash_Response
    std::shared_ptr<vacuum_msgs::srv::UnloadTrash_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UnloadTrash_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->score_gained != other.score_gained) {
      return false;
    }
    if (this->capacity_used != other.capacity_used) {
      return false;
    }
    return true;
  }
  bool operator!=(const UnloadTrash_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UnloadTrash_Response_

// alias to use template instance with default allocator
using UnloadTrash_Response =
  vacuum_msgs::srv::UnloadTrash_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vacuum_msgs

namespace vacuum_msgs
{

namespace srv
{

struct UnloadTrash
{
  using Request = vacuum_msgs::srv::UnloadTrash_Request;
  using Response = vacuum_msgs::srv::UnloadTrash_Response;
};

}  // namespace srv

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__STRUCT_HPP_
