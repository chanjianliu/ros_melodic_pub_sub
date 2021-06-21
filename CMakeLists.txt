cmake_minimum_required(VERSION 3.0.2)
project(liu_test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
 INCLUDE_DIRS include
#  LIBRARIES liu_test
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(
  liu_talker
  src/talker.cpp
)

target_link_libraries(
  liu_talker
  ${catkin_LIBRARIES}
)

add_executable(
  liu_listener
  src/listener.cpp
)

target_link_libraries(
  liu_listener
  ${catkin_LIBRARIES}
)

