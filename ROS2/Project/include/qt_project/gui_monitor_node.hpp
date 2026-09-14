#ifndef GUI_MONITOR_NODE_HPP
#define GUI_MONITOR_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include "qt_project/msg/seat_status.hpp"
#include "qt_project/msg/seat_command.hpp"
#include <QMainWindow>
#include "std_msgs/msg/int32_multi_array.hpp"
#include "qt_project/srv/get_route.hpp"
#include "qt_project/srv/process_penalty.hpp"
#include <vector>
#include <QPropertyAnimation>

namespace Ui
{
    class MainWindow;
}

class GuiMonitorNode : public QMainWindow, public rclcpp::Node
{
    private:
        //subscriber 생성
        rclcpp::Subscription<qt_project::msg::SeatStatus>::SharedPtr seat_status_subscriber;
        Ui::MainWindow *ui;
        //penalty subscriber 생성
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr penalty_subscriber;
        //경로 client 생성
        rclcpp::Client<qt_project::srv::GetRoute>::SharedPtr route_client;
   
        rclcpp::Client<qt_project::srv::ProcessPenalty>::SharedPtr process_penalty_client;
        int robot_position;
        
        std::vector<int> patrol_route;
        int current_route_index;
        rclcpp::TimerBase::SharedPtr movement_timer;
        QPropertyAnimation* robot_animation;
        bool patrol_in_progress; // 이미 순찰한 자리인지 아닌지 판단하는 플래그
        rclcpp::Publisher<qt_project::msg::SeatCommand>::SharedPtr seat_command_publisher;

        std::vector<int> penalty_seat_ids;
        rclcpp::TimerBase::SharedPtr patrol_timer;
        rclcpp::TimerBase::SharedPtr display_timer;

        int patrol_countdown;
        bool seat_occupied[6];
        bool seat_has_belongings[6];
        int seat_absence_start_time[6];

        std::vector<int> patrol_excluded_seat_ids;

        
    
    public:
        GuiMonitorNode();
        //SeatStatus가 들어왔을 때 실행할 함수
        void seatStatusCallback(const qt_project::msg::SeatStatus::SharedPtr message);
        void penaltyCallback(const std_msgs::msg::Int32MultiArray::SharedPtr message);
        void requestPatrolRoute(const std::vector<int>& seat_ids);
        //로봇 위치 GUI에서 나타내주는 함수
        void updateRobotPosition(int seat_id);
        void processPenalty(const std::vector<int>& seat_ids);
        void sendSeatCommand(int seat_id, bool occupied, bool has_belongings);
        void setSeatButtonRed(int seat_id);
        void setSeatButtonNormal(int seat_id);
        std::vector<int> getCurrentPatrolTargets();
        bool isSeatStillAbsent(int seat_id);
        void updateTimeLabels();
        void updateRobotHome();

};

#endif