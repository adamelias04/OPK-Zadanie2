cmake_minimum_required(VERSION 3.8)
project(vacuum_core)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(OpenCV REQUIRED)
find_package(yaml-cpp REQUIRED)

add_library(${PROJECT_NAME} SHARED
  src/Environment.cpp
  src/Robot.cpp
  src/Lidar.cpp
  src/WorldManager.cpp
  src/TrashFactory.cpp
  src/GameLogic.cpp
  src/BotController.cpp
  src/ConfigLoader.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
  ${OpenCV_LIBS}
  yaml-cpp
  Threads::Threads
)

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(OpenCV yaml-cpp)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_world_manager test/test_world_manager.cpp)
  target_link_libraries(test_world_manager ${PROJECT_NAME})

  ament_add_gtest(test_trash_factory test/test_trash_factory.cpp)
  target_link_libraries(test_trash_factory ${PROJECT_NAME})

  ament_add_gtest(test_config_loader test/test_config_loader.cpp)
  target_link_libraries(test_config_loader ${PROJECT_NAME})

  ament_add_gtest(test_bot_controller test/test_bot_controller.cpp)
  target_link_libraries(test_bot_controller ${PROJECT_NAME})
endif()

ament_package()
