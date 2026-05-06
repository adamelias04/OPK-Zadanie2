// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vacuum_msgs:srv/CollectTrash.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_HPP_
#define VACUUM_MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_HPP_

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
# define DEPRECATED__vacuum_msgs__srv__CollectTrash_Request __attribute__((deprecated))
#else
# define DEPRECATED__vacuum_msgs__srv__CollectTrash_Request __declspec(deprecated)
#endif

namespace vacuum_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CollectTrash_Request_
{
  using Type = CollectTrash_Request_<ContainerAllocator>;

  explicit CollectTrash_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->robot_radius = 0.0f;
    }
  }

  explicit CollectTrash_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc),
    robot_pos(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->robot_radius = 0.0f;
    }
  }

  // field types and members
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _robot_pos_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _robot_pos_type robot_pos;
  using _robot_radius_type =
    float;
  _robot_radius_type robot_radius;

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
  Type & set__robot_radius(
    const float & _arg)
  {
    this->robot_radius = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vacuum_msgs__srv__CollectTrash_Request
    std::shared_ptr<vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vacuum_msgs__srv__CollectTrash_Request
    std::shared_ptr<vacuum_msgs::srv::CollectTrash_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CollectTrash_Request_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->robot_pos != other.robot_pos) {
      return false;
    }
    if (this->robot_radius != other.robot_radius) {
      return false;
    }
    return true;
  }
  bool operator!=(const CollectTrash_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CollectTrash_Request_

// alias to use template instance with default allocator
using CollectTrash_Request =
  vacuum_msgs::srv::CollectTrash_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vacuum_msgs


// Include directives for member types
// Member 'collected'
#include "vacuum_msgs/msg/detail/trash_item__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vacuum_msgs__srv__CollectTrash_Response __attribute__((deprecated))
#else
# define DEPRECATED__vacuum_msgs__srv__CollectTrash_Response __declspec(deprecated)
#endif

namespace vacuum_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CollectTrash_Response_
{
  using Type = CollectTrash_Response_<ContainerAllocator>;

  explicit CollectTrash_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : collected(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->capacity_used = 0ul;
      this->capacity_max = 0ul;
    }
  }

  explicit CollectTrash_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : collected(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->capacity_used = 0ul;
      this->capacity_max = 0ul;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _collected_type =
    vacuum_msgs::msg::TrashItem_<ContainerAllocator>;
  _collected_type collected;
  using _capacity_used_type =
    uint32_t;
  _capacity_used_type capacity_used;
  using _capacity_max_type =
    uint32_t;
  _capacity_max_type capacity_max;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__collected(
    const vacuum_msgs::msg::TrashItem_<ContainerAllocator> & _arg)
  {
    this->collected = _arg;
    return *this;
  }
  Type & set__capacity_used(
    const uint32_t & _arg)
  {
    this->capacity_used = _arg;
    return *this;
  }
  Type & set__capacity_max(
    const uint32_t & _arg)
  {
    this->capacity_max = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vacuum_msgs__srv__CollectTrash_Response
    std::shared_ptr<vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vacuum_msgs__srv__CollectTrash_Response
    std::shared_ptr<vacuum_msgs::srv::CollectTrash_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CollectTrash_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->collected != other.collected) {
      return false;
    }
    if (this->capacity_used != other.capacity_used) {
      return false;
    }
    if (this->capacity_max != other.capacity_max) {
      return false;
    }
    return true;
  }
  bool operator!=(const CollectTrash_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CollectTrash_Response_

// alias to use template instance with default allocator
using CollectTrash_Response =
  vacuum_msgs::srv::CollectTrash_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vacuum_msgs

namespace vacuum_msgs
{

namespace srv
{

struct CollectTrash
{
  using Request = vacuum_msgs::srv::CollectTrash_Request;
  using Response = vacuum_msgs::srv::CollectTrash_Response;
};

}  // namespace srv

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__SRV__DETAIL__COLLECT_TRASH__STRUCT_HPP_
