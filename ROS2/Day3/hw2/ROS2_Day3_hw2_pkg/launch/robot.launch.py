from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():

    package_path = get_package_share_directory(
        'ROS2_Day3_hw2_pkg'
    )

    parameter_file = os.path.join(
        package_path,
        'config',
        'params.yaml'
    )

    traffic_light_node = Node(
        package='ROS2_Day3_hw2_pkg',
        executable='traffic_light_node',
        name='traffic_light',
        output='screen',
        parameters=[parameter_file]
    )

    vehicle_node = Node(
        package='ROS2_Day3_hw2_pkg',
        executable='vehicle_node',
        name='vehicle',
        output='screen',
        parameters=[parameter_file]
    )

    qt_simulator_node = Node(
        package='ROS2_Day3_hw2_pkg',
        executable='qt_simulator_node',
        name='qt_simulator',
        output='screen',
        parameters=[parameter_file]
    )

    return LaunchDescription([
        traffic_light_node,
        vehicle_node,
        qt_simulator_node
    ])