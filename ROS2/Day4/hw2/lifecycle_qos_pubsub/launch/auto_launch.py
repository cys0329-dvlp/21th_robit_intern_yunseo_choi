from launch import LaunchDescription
from launch.actions import EmitEvent, RegisterEventHandler
from launch.events import matches_action
from launch_ros.actions import LifecycleNode
from launch_ros.event_handlers import OnStateTransition
from launch_ros.events.lifecycle import ChangeState
from lifecycle_msgs.msg import Transition


def generate_launch_description():

    publisher = LifecycleNode(
    package='lifecycle_qos_pubsub',
    executable='lifecycle_publisher',
    name='lifecycle_publisher',
    namespace=''
    )   

    subscriber = LifecycleNode(
        package='lifecycle_qos_pubsub',
        executable='lifecycle_subscriber',
        name='lifecycle_subscriber',
        namespace=''
    )
    

    configure_publisher = EmitEvent(
        event=ChangeState(
            lifecycle_node_matcher=matches_action(publisher),
            transition_id=Transition.TRANSITION_CONFIGURE,
        )
    )

    activate_publisher = RegisterEventHandler(
        OnStateTransition(
            target_lifecycle_node=publisher,
            goal_state='inactive',
            entities=[
                EmitEvent(
                    event=ChangeState(
                        lifecycle_node_matcher=matches_action(publisher),
                        transition_id=Transition.TRANSITION_ACTIVATE,
                    )
                )
            ],
        )
    )

    configure_subscriber = EmitEvent(
        event=ChangeState(
            lifecycle_node_matcher=matches_action(subscriber),
            transition_id=Transition.TRANSITION_CONFIGURE,
        )
    )

    activate_subscriber = RegisterEventHandler(
        OnStateTransition(
            target_lifecycle_node=subscriber,
            goal_state='inactive',
            entities=[
                EmitEvent(
                    event=ChangeState(
                        lifecycle_node_matcher=matches_action(subscriber),
                        transition_id=Transition.TRANSITION_ACTIVATE,
                    )
                )
            ],
        )
    )

    return LaunchDescription([
        publisher,
        subscriber,

        configure_publisher,
        activate_publisher,

        configure_subscriber,
        activate_subscriber,
    ])