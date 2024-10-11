#include "hw_interface/hw_node.hpp"
#include "tf2/LinearMath/Quaternion.h"



using std::placeholders::_1;
using namespace std::chrono_literals;

HWNode::HWNode () : Node("hw_node"), count_(0)
    {
      ard_.setup("/dev/ttyAMA1");
      subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel", 100, std::bind(&HWNode::topic_callback, this, _1));
          // ard_.setup("/dev/ttyAMA1");
      odometry_transform_publisher_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

      odometry_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("/odom", 10);
     
      timer_ = this->create_wall_timer(
      100ms, std::bind(&OdomPub::timer_callback, this));

      
    
    }

void HWNode::topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
      double & x_vel = msg.get()->linear.x;
      double & y_vel = msg.get()->linear.y;
      double & ang_vel = msg.get()->angular.z;
      ard_.setSpeed(
      (int) (x_vel * 1000), (int) (y_vel * 1000), (int) (ang_vel * 1000)
      );

      RCLCPP_INFO(this->get_logger(), "SEND VEL");
    }

void HWNode::timer_callback()
    {
      auto message = nav_msgs::msg::Odometry();
      // ard_.readOdometry(pos_x, pos_y, pos_w, vel_x, vel_y, vel_w);
      tf2::Quaternion orientation;
      orientation.setRPY(0.0, 0.0, 0.0);

      time = get_clock()->now();

      // std::ostringstream strs;
      // strs << pos_x << " " << pos_y << " " << pos_w << " " << vel_x << " " << vel_y << " " << vel_w;
      // RCLCPP_INFO(this->get_logger(), strs.str().c_str());

      auto odometry_message = nav_msgs::msg::Odometry();
      odometry_message.header.stamp = time;
      odometry_message.pose.pose.position.x = 0.0;
      odometry_message.pose.pose.position.y = 0.0;
      odometry_message.pose.pose.orientation.x = orientation.x();
      odometry_message.pose.pose.orientation.y = orientation.y();
      odometry_message.pose.pose.orientation.z = orientation.z();
      odometry_message.pose.pose.orientation.w = orientation.w();
      odometry_message.twist.twist.linear.x = 0.0;
      odometry_message.twist.twist.linear.y = 0.0;
      odometry_message.twist.twist.angular.z = 0.0;
      odometry_publisher_->publish(odometry_message);

      geometry_msgs::msg::TransformStamped transform;

      transform.header.stamp = time;
      transform.header.frame_id = "odom";
      transform.child_frame_id = "base_link";
      transform.transform.translation.x = pos_x;
      transform.transform.translation.y = pos_y;
      transform.transform.rotation.x = orientation.x();
      transform.transform.rotation.y = orientation.y();
      transform.transform.rotation.z = orientation.z();
      transform.transform.rotation.w = orientation.w();
      odometry_transform_publisher_->sendTransform(transform);

      // message.data = "Hello, world! " + std::to_string(count_++);
      // RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }
