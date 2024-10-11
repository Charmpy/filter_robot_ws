#include <memory>
#include <chrono>
#include <functional>
#include <string>
#include <cmath>


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "hw_interface/config.hpp"
#include "hw_interface/arduino_comms.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/time.hpp"
#include "tf2_msgs/msg/tf_message.hpp"

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/transform_broadcaster.h"


class HWNode : public rclcpp::Node  {
    public:
        HWNode();
        void init(const rclcpp::Time & time);
        void timer_callback();
        void topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg);


        rclcpp::Time time;

        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;

        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odometry_publisher_;

        std::shared_ptr<tf2_ros::TransformBroadcaster> odometry_transform_publisher_;
        size_t count_;
        ArduinoComms ard_;
        double pos_x; double pos_y; double pos_w;
        double vel_x; double vel_y; double vel_w;
        double x_; double y_;
};
