from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():

    #패키지 경로 찾기
    package_dir = get_package_share_directory(
        'pytorch_object_detection'
    )

    #yaml 경로 만들기
    config_file = os.path.join(
        package_dir,
        'config',
        'yolo_detection.yaml'
    )

    return LaunchDescription([

        #카메라 노드 실행
        Node(
            package='pytorch_object_detection',
            executable='camera_node',
            name='camera_node'
        ),

        #inference 노드 실행 + yaml 전달
        Node(
            package='pytorch_object_detection',
            executable='inference_node',
            name='inference_node',
            parameters=[config_file]
        )
    ])