#ifndef PATROL_PLANNER_NODE_HPP
#define PATROL_PLANNER_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include "qt_project/patrol_planner.hpp"
#include "qt_project/msg/seat_status.hpp"
#include "qt_project/srv/get_route.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include "qt_project/srv/process_penalty.hpp"
#include "qt_project/msg/seat_command.hpp"

//ROS2 노드 만들어서 PatrolPlanner 감싸는 구조 

class PatrolPlannerNode : public rclcpp::Node
{
    private:
        PatrolPlanner planner;

        //Topic 활성화
        rclcpp::Publisher<qt_project::msg::SeatStatus>::SharedPtr seat_status_publisher;
        rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr penalty_publisher;

        //Service 활성화
        rclcpp::Service<qt_project::srv::GetRoute>::SharedPtr route_service;

        rclcpp::Service<qt_project::srv::ProcessPenalty>::SharedPtr process_penalty_service;
        rclcpp::TimerBase::SharedPtr status_timer;
        rclcpp::Subscription<qt_project::msg::SeatCommand>::SharedPtr seat_command_subscriber;
    public:
        PatrolPlannerNode();
        void publishSeatStatus(); //GUI가 이 토픽 subscrbe -> 좌석 상태 화면에 표시
        void seatCommandCallback(const qt_project::msg::SeatCommand::SharedPtr message);

};

#endif