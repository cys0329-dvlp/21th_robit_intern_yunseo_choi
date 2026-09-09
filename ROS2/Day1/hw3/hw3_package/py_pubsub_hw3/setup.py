from setuptools import find_packages, setup

package_name = 'py_pubsub_hw3'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='choiyuns',
    maintainer_email='okkyuns0329@gmail.com',
    description='ROS 2 퍼블리셔/서브스크라이버 예제',
    license='Apache License 2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'talker = py_pubsub_hw3.publisher_member_function:main',
            'listener = py_pubsub_hw3.subscriber_member_function:main',
        ],
    },
)
