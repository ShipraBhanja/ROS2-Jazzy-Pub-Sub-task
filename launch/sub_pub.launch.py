from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sub_pub',
            executable='publisher_node',
            output='screen'
        ),
        Node(
            package='sub_pub',
            executable='subscriber_node',
            output='screen'
        )
    ])

