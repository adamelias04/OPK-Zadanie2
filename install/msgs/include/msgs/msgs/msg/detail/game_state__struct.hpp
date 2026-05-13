// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__GAME_STATE__STRUCT_HPP_
#define MSGS__MSG__DETAIL__GAME_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'collected'
#include "msgs/msg/detail/trash_count__struct.hpp"
// Member 'active_trash'
#include "msgs/msg/detail/trash_item__struct.hpp"
// Member 'robots'
#include "msgs/msg/detail/robot_status__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__msgs__msg__GameState __attribute__((deprecated))
#else
# define DEPRECATED__msgs__msg__GameState __declspec(deprecated)
#endif

namespace msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GameState_
{
  using Type = GameState_<ContainerAllocator>;

  explicit GameState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = "";
      this->phase = "";
      this->elapsed_seconds = 0.0f;
      this->score = 0l;
      this->winner = "";
    }
  }

  explicit GameState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mode(_alloc),
    phase(_alloc),
    winner(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = "";
      this->phase = "";
      this->elapsed_seconds = 0.0f;
      this->score = 0l;
      this->winner = "";
    }
  }

  // field types and members
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _phase_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _phase_type phase;
  using _elapsed_seconds_type =
    float;
  _elapsed_seconds_type elapsed_seconds;
  using _score_type =
    int32_t;
  _score_type score;
  using _collected_type =
    std::vector<msgs::msg::TrashCount_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs::msg::TrashCount_<ContainerAllocator>>>;
  _collected_type collected;
  using _active_trash_type =
    std::vector<msgs::msg::TrashItem_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs::msg::TrashItem_<ContainerAllocator>>>;
  _active_trash_type active_trash;
  using _robots_type =
    std::vector<msgs::msg::RobotStatus_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs::msg::RobotStatus_<ContainerAllocator>>>;
  _robots_type robots;
  using _winner_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _winner_type winner;

  // setters for named parameter idiom
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__phase(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->phase = _arg;
    return *this;
  }
  Type & set__elapsed_seconds(
    const float & _arg)
  {
    this->elapsed_seconds = _arg;
    return *this;
  }
  Type & set__score(
    const int32_t & _arg)
  {
    this->score = _arg;
    return *this;
  }
  Type & set__collected(
    const std::vector<msgs::msg::TrashCount_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs::msg::TrashCount_<ContainerAllocator>>> & _arg)
  {
    this->collected = _arg;
    return *this;
  }
  Type & set__active_trash(
    const std::vector<msgs::msg::TrashItem_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs::msg::TrashItem_<ContainerAllocator>>> & _arg)
  {
    this->active_trash = _arg;
    return *this;
  }
  Type & set__robots(
    const std::vector<msgs::msg::RobotStatus_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs::msg::RobotStatus_<ContainerAllocator>>> & _arg)
  {
    this->robots = _arg;
    return *this;
  }
  Type & set__winner(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->winner = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs::msg::GameState_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs::msg::GameState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs::msg::GameState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs::msg::GameState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs::msg::GameState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::GameState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs::msg::GameState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::GameState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs::msg::GameState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs::msg::GameState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs__msg__GameState
    std::shared_ptr<msgs::msg::GameState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs__msg__GameState
    std::shared_ptr<msgs::msg::GameState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GameState_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->phase != other.phase) {
      return false;
    }
    if (this->elapsed_seconds != other.elapsed_seconds) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    if (this->collected != other.collected) {
      return false;
    }
    if (this->active_trash != other.active_trash) {
      return false;
    }
    if (this->robots != other.robots) {
      return false;
    }
    if (this->winner != other.winner) {
      return false;
    }
    return true;
  }
  bool operator!=(const GameState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GameState_

// alias to use template instance with default allocator
using GameState =
  msgs::msg::GameState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__GAME_STATE__STRUCT_HPP_
