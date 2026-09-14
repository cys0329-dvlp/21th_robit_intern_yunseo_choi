#include "qt_project/patrol_planner_node.hpp"
#include <ctime>
#include <chrono>

PatrolPlannerNode::PatrolPlannerNode() //생성자
    : Node("patrol_planner_node") // 노드 이름: patrol_planner_node
{
    planner.addSeat(Seat(1, 0.0, 0.0));
    planner.addSeat(Seat(2, 1.0, 0.0));
    planner.addSeat(Seat(3, 2.0, 0.0));
    planner.addSeat(Seat(4, 0.0, 1.0));
    planner.addSeat(Seat(5, 2.0, 1.0)); 

    for (int seat_id = 1; seat_id <= 5; seat_id++)
    {
        planner.updateSeatStatus(seat_id, false, false);
    }
    //SeatStatus 메시지 사용하는 publisher생성 / 토픽 이름: /studt_room/seat_status / queue depth 10 --> 엄청 빠르게 발생하는 구조가 아니기에 10이면 충분
    seat_status_publisher = this->create_publisher<qt_project::msg::SeatStatus>("/study_room/seat_status",10);
    penalty_publisher = this->create_publisher<std_msgs::msg::Int32MultiArray>("/study_room/penalty_seats", 10);

    seat_command_subscriber =
    this->create_subscription<qt_project::msg::SeatCommand>(
        "/study_room/seat_command",
        10,
        std::bind(
            &PatrolPlannerNode::seatCommandCallback,
            this,
            std::placeholders::_1
        )
    );

    //서비스 통신 통로 만들기
    route_service =
    this->create_service<qt_project::srv::GetRoute>(
        "/patrol/get_route", //Service 이름
        [this](const std::shared_ptr<qt_project::srv::GetRoute::Request> request,
               std::shared_ptr<qt_project::srv::GetRoute::Response> response)
        {
            RCLCPP_INFO(this->get_logger(), "요청받은 좌석 수: %ld", request->seat_ids.size());
            
            
            //service 요청이 비어있을 시 예외처리
            if (request->seat_ids.empty())
            {
                RCLCPP_WARN(this->get_logger(), "순찰 요청 좌석이 없습니다.");
                response->route.clear();
                return;
            }     
            
            for (int seat_id : request->seat_ids)
            {
                if (planner.isValidSeat(seat_id) == false)
                {
                    RCLCPP_WARN(this->get_logger(), "존재하지 않는 좌석 ID: %d", seat_id);

                    response->route.clear();
                    return;
                }

                RCLCPP_INFO(this->get_logger(), "요청 좌석 ID: %d", seat_id);
            }

            std::vector<int> route = planner.makePatrolRoute(request->seat_ids);
            
            for (int seat_id : route)
            {
                RCLCPP_INFO(this->get_logger(), "순찰 경로 좌석 ID: %d", seat_id);
            }
            
            //Service 요청자에게 전달
            response->route = route;
        }
    );


    process_penalty_service =
    this->create_service<qt_project::srv::ProcessPenalty>(
        "/patrol/process_penalty",
        [this](
            const std::shared_ptr<qt_project::srv::ProcessPenalty::Request> request,
            std::shared_ptr<qt_project::srv::ProcessPenalty::Response> response)
        {
            if (request->seat_ids.empty())
            {
                RCLCPP_WARN(
                    this->get_logger(),
                    "처리할 패널티 좌석이 없습니다."
                );

                response->success = false;
                return;
            }

            for (int seat_id : request->seat_ids)
            {
                if (planner.isValidSeat(seat_id) == false)
                {
                    RCLCPP_WARN(
                        this->get_logger(),
                        "존재하지 않는 좌석 ID: %d",
                        seat_id
                    );

                    response->success = false;
                    return;
                }
            }

            planner.processPenalty(request->seat_ids);

            response->success = true;

            RCLCPP_INFO(
                this->get_logger(),
                "패널티 처리가 완료되었습니다."
            );
        }
    );


    //1초 마다 publishSeatStatus 호출
    status_timer = this->create_wall_timer(
        std::chrono::seconds(1),
        std::bind(&PatrolPlannerNode::publishSeatStatus, this)
    );
}

void PatrolPlannerNode::publishSeatStatus()
{
    for (int seat_id = 1; seat_id <= 5; seat_id++)
    {
        qt_project::msg::SeatStatus message;

        bool occupied;
        bool has_belongings;
        int absence_start_time;

        planner.getSeatStatus(
            seat_id,
            occupied,
            has_belongings,
            absence_start_time
        );

        message.seat_id = seat_id;
        message.occupied = occupied;
        message.has_belongings = has_belongings;
        message.absence_start_time = absence_start_time;

        seat_status_publisher->publish(message);
    }

    std::vector<int> penalty_seat_ids =
        planner.getPenaltySeatIDs();

    std_msgs::msg::Int32MultiArray penalty_message;

    for (int seat_id : penalty_seat_ids)
    {
        penalty_message.data.push_back(seat_id);
    }

    penalty_publisher->publish(penalty_message);
}

void PatrolPlannerNode::seatCommandCallback(
    const qt_project::msg::SeatCommand::SharedPtr message)
{
    if (planner.isValidSeat(message->seat_id) == false)
    {
        RCLCPP_WARN(
            this->get_logger(),
            "존재하지 않는 좌석 ID: %d",
            message->seat_id
        );

        return;
    }

    planner.updateSeatStatus(
        message->seat_id,
        message->occupied,
        message->has_belongings
    );

    RCLCPP_INFO(
        this->get_logger(),
        "좌석 %d 상태 변경: occupied=%s, belongings=%s",
        message->seat_id,
        message->occupied ? "true" : "false",
        message->has_belongings ? "true" : "false"
    );
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv); //ROS2 초기화

    //만든 노드 실행
    auto node = std::make_shared<PatrolPlannerNode>();

    //서비스 요청 계속 기다림
    rclcpp::spin(node);

    //ROS2 종료
    rclcpp::shutdown();

    return 0;
}