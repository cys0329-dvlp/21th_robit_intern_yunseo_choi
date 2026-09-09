# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from std_msgs.msg import Int32
from std_msgs.msg import Float32
from std_msgs.msg import Bool

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(String, 'string', 10)
        self.text_publisher_ = self.create_publisher(Int32, 'number', 10)
        self.float_publisher_ = self.create_publisher(Float32, 'float_number', 10)
        self.bool_publisher_ = self.create_publisher(Bool, 'bool_number', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World:'
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)

        text_msg = Int32()
        text_msg.data = self.i
        self.text_publisher_.publish(text_msg)
        self.get_logger().info('Publishing: "%s"' % text_msg.data)

        float_msg = Float32()
        float_msg.data = float(self.i)
        self.float_publisher_.publish(float_msg)
        self.get_logger().info('Publishing: "%s"' % float_msg.data)

        bool_msg = Bool()
        bool_msg.data = bool(self.i)
        self.bool_publisher_.publish(bool_msg)
        self.get_logger().info('Publishing: "%s"' % bool_msg.data)

        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
