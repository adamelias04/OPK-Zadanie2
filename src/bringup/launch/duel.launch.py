from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

import os


def generate_launch_description():
    pkg_share = get_package_share_directory('bringup')
    default_cfg = os.path.join(pkg_share, 'config', 'game_config.yaml')
    default_rviz = os.path.join(pkg_share, 'config', 'vacuum.rviz')

    cfg_arg = DeclareLaunchArgument('config_file', default_value=default_cfg)
    rviz_arg = DeclareLaunchArgument('rviz_config', default_value=default_rviz)
    use_rviz_arg = DeclareLaunchArgument('use_rviz', default_value='true')

    cfg = LaunchConfiguration('config_file')
    rviz_cfg = LaunchConfiguration('rviz_config')

    game = Node(
        package='nodes',
        executable='game_node',
        name='game_node',
        output='screen',
        parameters=[{'config_file': cfg}],
    )

    player_robot = Node(
        package='nodes',
        executable='robot_node',
        name='player_robot_node',
        output='screen',
        parameters=[{
            'config_file': cfg,
            'robot_id': 'player',
            'start_x': 10.0,
            'start_y': 36.2,
            'start_theta': 0.0,
            'ghost': False,
        }],
    )

    player_lidar = Node(
        package='nodes',
        executable='lidar_node',
        name='player_lidar_node',
        output='screen',
        parameters=[{
            'config_file': cfg,
            'robot_id': 'player',
        }],
    )

    bot_robot = Node(
        package='nodes',
        executable='robot_node',
        name='bot_robot_node',
        output='screen',
        parameters=[{
            'config_file': cfg,
            'robot_id': 'bot',
            'start_x': 14.0,
            'start_y': 35.2,
            'start_theta': 0.0,
            'ghost': True,
        }],
    )

    bot_lidar = Node(
        package='nodes',
        executable='lidar_node',
        name='bot_lidar_node',
        output='screen',
        parameters=[{
            'config_file': cfg,
            'robot_id': 'bot',
        }],
    )

    # NOTE: teleop_node is intentionally NOT launched here.
    # Run it manually in a separate terminal so it can capture keyboard input:
    #   ros2 run nodes teleop_node --ros-args -p robot_id:=player
    # (launching teleop with a prefix like 'xterm -e' only works if xterm is
    #  installed; the separate-terminal pattern matches teleop_twist_keyboard.)

    bot_ai = Node(
        package='nodes',
        executable='bot_node',
        name='bot_controller',
        output='screen',
        parameters=[{
            'robot_id': 'bot',
            'station_x': 12.0,
            'station_y': 33.2,
            'max_linear': 1.5,
            'max_angular': 2.0,
            'capacity_max': 5,
        }],
    )

    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_cfg],
        condition=None,
    )

    return LaunchDescription([
        cfg_arg, rviz_arg, use_rviz_arg,
        game,
        player_robot, player_lidar,
        bot_robot, bot_lidar,
        bot_ai,
        rviz,
    ])
