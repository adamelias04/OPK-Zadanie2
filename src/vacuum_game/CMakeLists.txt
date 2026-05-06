cmake_minimum_required(VERSION 3.8)
project(vacuum_game)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(vacuum_core REQUIRED)
find_package(vacuum_msgs REQUIRED)

add_executable(game_node src/game_node.cpp)
ament_target_dependencies(game_node
  rclcpp geometry_msgs nav_msgs std_msgs visualization_msgs
  vacuum_core vacuum_msgs
)

add_executable(teleop_node src/teleop_node.cpp)
ament_target_dependencies(teleop_node
  rclcpp geometry_msgs
)

add_executable(bot_node src/bot_node.cpp)
ament_target_dependencies(bot_node
  rclcpp geometry_msgs
  vacuum_core vacuum_msgs
)

install(TARGETS game_node teleop_node bot_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
