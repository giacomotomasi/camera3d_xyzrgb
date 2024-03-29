cmake_minimum_required(VERSION 3.0.2)
project(camera3d_xyzrgb)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  pcl_ros
  pcl_conversions
  message_generation
  visualization_msgs
  tf
  tf_conversions
  rviz_visual_tools
)

add_message_files(
  FILES
  ClustersArray.msg
  BoundingBox3D.msg
  BoundingBox3DArray.msg
)

generate_messages(
  DEPENDENCIES
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS 
  message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include
)

add_executable(detector_node src/detector_node.cpp src/Detector.cpp)
target_link_libraries(detector_node ${catkin_LIBRARIES})

add_executable(bbox_node src/bbox_node.cpp src/Bbox.cpp)
target_link_libraries(bbox_node ${catkin_LIBRARIES})

add_executable(camera_tf_broadcaster src/camera_tf_broadcaster.cpp)
target_link_libraries(camera_tf_broadcaster ${catkin_LIBRARIES})

add_dependencies(detector_node camera3d_xyzrgb_generate_messages_cpp)
add_dependencies(bbox_node camera3d_xyzrgb_generate_messages_cpp)
