import sys

from req_res_str_service.srv import ReqRes
import rclpy
from rclpy.node import Node


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(ReqRes, 'cam_service')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = ReqRes.Request()

    def send_request(self, a):
        self.req.req = a
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


def main(args=None):
    rclpy.init(args=args)

    #### Main programm RPI ####

    minimal_client = MinimalClientAsync()
    response = minimal_client.send_request(sys.argv[1])
    minimal_client.get_logger().info(
        f'Result of {sys.argv[1]} is {response.res}')

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()