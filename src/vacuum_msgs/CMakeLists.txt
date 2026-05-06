cmake_minimum_required(VERSION 3.8)
project(vacuum_msgs)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/TrashItem.msg"
  "msg/TrashCount.msg"
  "msg/RobotStatus.msg"
  "msg/GameState.msg"
  "srv/CollectTrash.srv"
  "srv/UnloadTrash.srv"
  "srv/ResetGame.srv"
  DEPENDENCIES std_msgs geometry_msgs
)

ament_package()
