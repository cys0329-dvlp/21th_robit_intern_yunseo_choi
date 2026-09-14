from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    #터미널에서 직접했던 launch 명령어를 launch 파일로 작성
    publisher = Node(
        package='lifecycle_qos_pubsub',
        executable='lifecycle_publisher',
        name='lifecycle_publisher'
    )

    #터미널에서 직접했던 launch 명령어를 launch 파일로 작성
    subscriber = Node(
        package='lifecycle_qos_pubsub',
        executable='lifecycle_subscriber',
        name='lifecycle_subscriber'
    )

    return LaunchDescription([
        publisher,
        subscriber
    ])