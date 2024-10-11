#include <memory>
#include <chrono>
#include <functional>
#include <string>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
// #include "hw_interface/config.hpp"
// #include "hw_interface/arduino_comms.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/time.hpp"
#include "tf2_msgs/msg/tf_message.hpp"

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/transform_broadcaster.h"


class OdomPub : public rclcpp::Node  {
    public:
        OdomPub();
        void init(const rclcpp::Time & time);
        void timer_callback();
        rclcpp::Time time;

        rclcpp::TimerBase::SharedPtr timer_;

        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odometry_publisher_;

        std::shared_ptr<tf2_ros::TransformBroadcaster> odometry_transform_publisher_;
    
};
