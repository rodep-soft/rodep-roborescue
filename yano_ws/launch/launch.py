import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, IncludeLaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    return LaunchDescription([
        # Launch the driver node
        Node(
            package="joy",
            # namespace="",
            executable="joy_node",
            name="pub_joy"
        ),
        Node(
            package='operator',  # Replace with the actual package name
            executable='operator_node',  # The executable for the driver node
            name='operator_node',  # Name of the node
            output='screen',  # Output logs to screen
            parameters=[],
            remappings=[]
        ),

        # Launch the operator node
        Node(
            package='crawler_driver',  # Replace with the actual package name
            executable='crawler_driver_node',  # The executable for the operator node
            name='crawler_driver_node',  # Name of the node
            output='screen',  # Output logs to screen
            parameters=[],
            remappings=[]
        ),
        Node(
            package='flipper_driver',
            executable='flipper_driver_node',
            name='flipper_driver_node',
            output='screen',
            parameters=[{'port_name': '/dev/ttyUSB0'}],
            remappings=[]

        ),
    ])
