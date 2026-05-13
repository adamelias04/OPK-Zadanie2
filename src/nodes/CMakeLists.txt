cmake_minimum_required(VERSION 3.8)
project(nodes)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(core REQUIRED)
find_package(msgs REQUIRED)

add_executable(robot_node src/robot_node.cpp)
ament_target_dependencies(robot_node
  rclcpp geometry_msgs sensor_msgs nav_msgs std_msgs
  tf2 tf2_ros tf2_geometry_msgs
  visualization_msgs
  core msgs
)

add_executable(lidar_node src/lidar_node.cpp)
ament_target_dependencies(lidar_node
  rclcpp geometry_msgs sensor_msgs std_msgs
  core msgs
)

add_executable(game_node src/game_node.cpp)
ament_target_dependencies(game_node
  rclcpp geometry_msgs nav_msgs std_msgs visualization_msgs
  core msgs
)

add_executable(teleop_node src/teleop_node.cpp)
ament_target_dependencies(teleop_node
  rclcpp geometry_msgs
)

add_executable(bot_node src/bot_node.cpp)
ament_target_dependencies(bot_node
  rclcpp geometry_msgs
  core msgs
)

add_executable(pvp_teleop_node src/pvp_teleop_node.cpp)
ament_target_dependencies(pvp_teleop_node
  rclcpp geometry_msgs
)

install(TARGETS robot_node lidar_node game_node teleop_node bot_node pvp_teleop_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
