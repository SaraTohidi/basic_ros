cmake_minimum_required(VERSION 3.0.2)
project(manipulating_ros_msgs)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  genmsg
  dynamic_reconfigure
  geometry_msgs
)

generate_dynamic_reconfigure_options(
  cfg/freqConfig.cfg
)
add_message_files(
  FILES
  message.msg
)
generate_messages(
   DEPENDENCIES
   std_msgs
)


catkin_add_gtest(utest src/test.cpp)
if(TARGET utest)
  target_link_libraries(utest ${catkin_LIBRARIES})
endif()

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES freq_float
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime geometry_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(manipulating_msgs src/main.cpp)
 target_link_libraries(manipulating_msgs
   ${catkin_LIBRARIES}
 )
 
add_dependencies(manipulating_msgs manipulating_ros_msgs_gencfg)


add_executable(listener src/listener.cpp)
 target_link_libraries(listener
   ${catkin_LIBRARIES}
 )



