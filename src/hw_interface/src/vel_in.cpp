#include "hw_interface/vel_in.hpp"
#include "tf2/LinearMath/Quaternion.h"



using std::placeholders::_1;
using namespace std::chrono_literals;

HWInterface::HWInterface () : Node("hw_interface2"), count_(0)
    {
      ard_.setup("/dev/ttyUSB0");
      subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel", 100, std::bind(&HWInterface::topic_callback, this, _1));
    }

void HWInterface::topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
      double & x_vel = msg.get()->linear.x;
      double & y_vel = msg.get()->linear.y;
      double & ang_vel = msg.get()->angular.z;
      ard_.setSpeed(
      (int) (x_vel * 1000), (int) (y_vel * 1000), (int) (ang_vel * 1000)
      );

      RCLCPP_INFO(this->get_logger(), "SEND VEL");
    }
  