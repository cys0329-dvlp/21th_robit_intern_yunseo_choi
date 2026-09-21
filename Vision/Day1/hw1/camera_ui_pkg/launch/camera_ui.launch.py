import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    pkg_share = get_package_share_directory(
        'camera_ui_pkg')

    config_path = os.path.join(
        pkg_share,
        'config',
        'camera_ui.yaml')

    camera_node = Node(
        package='camera_ui_pkg',
        executable='camera_node',
        name='camera_node',
        output='screen',
        parameters=[config_path],
    )

    ui_node = Node(
        package='camera_ui_pkg',
        executable='ui_node',
        name='ui_node',
        output='screen',
        parameters=[config_path],
    )

    return LaunchDescription([
        camera_node,
        ui_node,
    ])