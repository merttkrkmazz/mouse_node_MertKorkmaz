cmake_minimum_required(VERSION 2.8.3)
project(mouse_node_yourname)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(mouse_node src/mouse_node.cpp)  # Replace with your source file

target_link_libraries(mouse_node
  ${catkin_LIBRARIES}
)

