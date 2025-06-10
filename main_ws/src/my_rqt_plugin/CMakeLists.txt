cmake_minimum_required(VERSION 3.8)
project(my_rqt_plugin)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)


find_package(rclcpp REQUIRED)
find_package(rqt_gui_cpp REQUIRED)
find_package(pluginlib REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_library(${PROJECT_NAME} SHARED
  src/my_plugin.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME}
  Qt5::Widgets
  rclcpp::rclcpp
  rqt_gui_cpp::rqt_gui_cpp
)

pluginlib_export_plugin_description_file(${PROJECT_NAME} plugin.xml)

install(DIRECTORY include/
  DESTINATION include
)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_export_dependencies(
  rclcpp
  rqt_gui_cpp
  pluginlib
  Qt5
)

ament_package()