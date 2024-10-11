cmake_minimum_required(VERSION 3.8)
project(hw_interface)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()



if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(serial REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_msgs  REQUIRED)


add_executable(vel_in src/vel_in_node.cpp src/vel_in.cpp)
ament_target_dependencies(vel_in  rclcpp std_msgs nav_msgs tf2_ros tf2 tf2_msgs geometry_msgs nav_msgs serial)

add_executable(odom_pub src/odom_pub_node.cpp src/odometry_publisher2.cpp)
ament_target_dependencies(odom_pub  rclcpp std_msgs nav_msgs tf2_ros tf2 tf2_msgs geometry_msgs nav_msgs serial)

add_library(hw_interface SHARED src/vel_in.cpp src/arduino_comms.cpp)

include_directories(include)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
install(TARGETS
  vel_in
  odom_pub
  DESTINATION lib/${PROJECT_NAME})

ament_package()



# cmake_minimum_required(VERSION 3.8)
# project(hw_interface)


# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()



# if(NOT CMAKE_CXX_STANDARD)
#   set(CMAKE_CXX_STANDARD 14)
# endif()

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(std_msgs REQUIRED)
# find_package(serial REQUIRED)
# find_package(geometry_msgs REQUIRED)

# add_library(vel_in SHARED src/vel_in.cpp src/arduino_comms.cpp)

# target_include_directories(
#   vel_in
#   PRIVATE
#   include
# )

# ament_target_dependencies(
#   vel_in
#   geometry_msgs
#   serial
#   rclcpp
#   std_msgs

# )

# install(
#   TARGETS vel_in 
#   DESTINATION lib
# )

# ament_export_libraries(
#   vel_in
# )


# add_executable(robo_node src/vel_in_node.cpp)

# ament_target_dependencies(robo_node  rclcpp std_msgs geometry_msgs serial)

# # add_library(hw_interface SHARED src/vel_in.cpp src/arduino_comms.cpp)

# include_directories(include)


# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   # the following line skips the linter which checks for copyrights
#   # comment the line when a copyright and license is added to all source files
#   set(ament_cmake_copyright_FOUND TRUE)
#   # the following line skips cpplint (only works in a git repo)
#   # comment the line when this package is in a git repo and when
#   # a copyright and license is added to all source files
#   set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()
# install(TARGETS
#   robo_node
#   DESTINATION lib/${PROJECT_NAME})

# ament_package()
