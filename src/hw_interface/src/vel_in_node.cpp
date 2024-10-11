#include <hw_interface/vel_in.hpp>
#include <rclcpp/rclcpp.hpp>


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HWInterface>());
  rclcpp::shutdown();
  return 0;
}