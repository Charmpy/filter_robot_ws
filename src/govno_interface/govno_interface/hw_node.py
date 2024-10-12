import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from geometry_msgs.msg import Twist
from .serial_flex import SerialFlex

class HWNode(Node):

    def __init__(self):
        super().__init__('hw_node')
        self.subscription = self.create_subscription(
            Twist,
            'cmd_vel',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.SER = SerialFlex()

    def listener_callback(self, msg):
        # self.get_logger().info(f"{msg.linear.x} {msg.linear.y} {msg.angular.z}")
        ans = self.SER.send_vel(msg.linear.x, msg.linear.y, msg.angular.z)
        self.get_logger().info(ans)

    # def timer_callback(self):
    #     msg = String()
    #     msg.data = 'Hello World: %d' % self.i
    #     self.publisher_.publish(msg)
    #     self.get_logger().info('Publishing: "%s"' % msg.data)
    #     self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = HWNode()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()