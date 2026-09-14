#include "qt_project/gui_monitor_node.hpp"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
#include <functional>
#include <chrono>
#include <ctime>
#include <algorithm>


GuiMonitorNode::GuiMonitorNode()
    : QMainWindow(),
      Node("gui_monitor_node"),
      robot_position(1),
      current_route_index(0),
      robot_animation(nullptr),
      patrol_in_progress(false),
      patrol_countdown(10)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    // 좌석 상태 초기화
    for (int i = 1; i <= 5; i++)
    {
        seat_occupied[i] = false;
        seat_has_belongings[i] = false;
        seat_absence_start_time[i] = 0;
    }

    // 로봇 초기 위치
    ui->robotLabel->move(290, 460);
    robot_position = 1;

    ui->robotPositionLabel->setText("로봇 처음 위치");
    ui->patrolTimerLabel->setText("다음 순찰: 10초");


    // =========================================================
    // 1번 좌석 상태 변경
    // =========================================================

    connect(
        ui->seat1SitButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(1, true, false);
        }
    );

    connect(
        ui->seat1LeaveButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(1, false, true);
        }
    );

    connect(
        ui->seat1GoHomeButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(1, false, false);
        }
    );


    // =========================================================
    // 2번 좌석 상태 변경
    // =========================================================

    connect(
        ui->seat2SitButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(2, true, false);
        }
    );

    connect(
        ui->seat2LeaveButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(2, false, true);
        }
    );

    connect(
        ui->seat2GoHomeButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(2, false, false);
        }
    );


    // =========================================================
    // 3번 좌석 상태 변경
    // =========================================================

    connect(
        ui->seat3SitButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(3, true, false);
        }
    );

    connect(
        ui->seat3LeaveButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(3, false, true);
        }
    );

    connect(
        ui->seat3GoHomeButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(3, false, false);
        }
    );


    // =========================================================
    // 4번 좌석 상태 변경
    // =========================================================

    connect(
        ui->seat4SitButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(4, true, false);
        }
    );

    connect(
        ui->seat4LeaveButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(4, false, true);
        }
    );

    connect(
        ui->seat4GoHomeButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(4, false, false);
        }
    );


    // =========================================================
    // 5번 좌석 상태 변경
    // =========================================================

    connect(
        ui->seat5SitButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(5, true, false);
        }
    );

    connect(
        ui->seat5LeaveButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(5, false, true);
        }
    );

    connect(
        ui->seat5GoHomeButton,
        &QPushButton::clicked,
        [this]()
        {
            sendSeatCommand(5, false, false);
        }
    );


    // =========================================================
    // 좌석 상태 Subscriber
    // =========================================================

    seat_status_subscriber =
    this->create_subscription<qt_project::msg::SeatStatus>(
        "/study_room/seat_status",
        10,
        std::bind(
            &GuiMonitorNode::seatStatusCallback,
            this,
            std::placeholders::_1
        )
    );


    // =========================================================
    // 패널티 좌석 Subscriber
    // =========================================================

    penalty_subscriber =
    this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/study_room/penalty_seats",
        10,
        std::bind(
            &GuiMonitorNode::penaltyCallback,
            this,
            std::placeholders::_1
        )
    );


    // =========================================================
    // 순찰 경로 Service Client
    // =========================================================

    route_client =
    this->create_client<qt_project::srv::GetRoute>(
        "/patrol/get_route"
    );


    // =========================================================
    // 좌석 상태 변경 Publisher
    // =========================================================

    seat_command_publisher =
    this->create_publisher<qt_project::msg::SeatCommand>(
        "/study_room/seat_command",
        10
    );


    // =========================================================
    // 패널티 처리 Service Client
    // =========================================================

    process_penalty_client =
    this->create_client<qt_project::srv::ProcessPenalty>(
        "/patrol/process_penalty"
    );


    // =========================================================
    // 로봇 이동
    //
    // QPropertyAnimation이 2초 동안 이동을 담당한다.
    // 애니메이션이 끝나면 현재 좌석을 확인하고
    // 다음 좌석으로 이동한다.
    // =========================================================

    movement_timer = this->create_wall_timer(
        std::chrono::milliseconds(100),
        [this]()
        {
            // 실제 이동은 QPropertyAnimation이 담당한다.
            // movement_timer는 사용하지 않는다.
        }
    );


    // =========================================================
    // 순찰 카운트다운
    //
    // 10 → 9 → ... → 1 → 0
    // 0초가 되는 순간 순찰 시작
    // =========================================================

    display_timer = this->create_wall_timer(
        std::chrono::seconds(1),
        [this]()
        {
            updateTimeLabels();

            // 순찰 중에는 카운트다운을 진행하지 않는다.
            if (patrol_in_progress)
            {
                ui->patrolTimerLabel->setText("순찰 중");
                return;
            }

            patrol_countdown--;

            ui->patrolTimerLabel->setText(
                QString("다음 순찰: %1초")
                    .arg(patrol_countdown)
            );


            // =================================================
            // 0초가 되는 순간 순찰 시작
            // =================================================

            if (patrol_countdown == 0)
            {
                std::vector<int> patrol_targets =
                    getCurrentPatrolTargets();


                // 순찰 대상이 없는 경우
                if (patrol_targets.empty())
                {
                    patrol_countdown = 10;

                    ui->patrolTimerLabel->setText(
                        "다음 순찰: 10초"
                    );

                    return;
                }


                // 순찰 시작
                patrol_in_progress = true;


                // 현재 순찰 대상 확정
                // 이 순간 이후 새로 생긴 대상은
                // 현재 순찰에 추가되지 않는다.
                for (int seat_id : patrol_targets)
                {
                    bool already_excluded = false;

                    for (int excluded_id :
                         patrol_excluded_seat_ids)
                    {
                        if (excluded_id == seat_id)
                        {
                            already_excluded = true;
                            break;
                        }
                    }

                    if (already_excluded == false)
                    {
                        patrol_excluded_seat_ids.push_back(
                            seat_id
                        );
                    }
                }


                ui->patrolTimerLabel->setText("순찰 중");

                requestPatrolRoute(patrol_targets);
            }
        }
    );
}


// =============================================================
// 좌석 상태 Callback
// =============================================================

void GuiMonitorNode::seatStatusCallback(
    const qt_project::msg::SeatStatus::SharedPtr message)
{
    if (message->seat_id < 1 ||
        message->seat_id > 5)
    {
        return;
    }

    seat_occupied[message->seat_id] =
        message->occupied;

    seat_has_belongings[message->seat_id] =
        message->has_belongings;

    seat_absence_start_time[message->seat_id] =
        message->absence_start_time;


    // =========================================================
    // 착석 또는 소지품 없음
    //
    // 해당 좌석은 새로운 이석 사이클을 시작할 수 있도록
    // 순찰 제외 목록에서 제거한다.
    // =========================================================

    if (message->occupied == true ||
        message->has_belongings == false)
    {
        patrol_excluded_seat_ids.erase(
            std::remove(
                patrol_excluded_seat_ids.begin(),
                patrol_excluded_seat_ids.end(),
                message->seat_id
            ),
            patrol_excluded_seat_ids.end()
        );
    }


    // =========================================================
    // 상태 출력
    // =========================================================

    if (message->occupied == true)
    {
        RCLCPP_INFO(
            this->get_logger(),
            "좌석 %d 상태: 사용 중",
            message->seat_id
        );
    }
    else
    {
        if (message->has_belongings == true)
        {
            RCLCPP_INFO(
                this->get_logger(),
                "좌석 %d 상태: 자리 비움, 소지품 있음",
                message->seat_id
            );
        }
        else
        {
            RCLCPP_INFO(
                this->get_logger(),
                "좌석 %d 상태: 비어 있음",
                message->seat_id
            );
        }
    }


    // =========================================================
    // 상태 Label 변경
    // =========================================================

    QLabel* statusLabel = nullptr;

    if (message->seat_id == 1)
    {
        statusLabel = ui->seatStatusLabel1;
    }
    else if (message->seat_id == 2)
    {
        statusLabel = ui->seatStatusLabel2;
    }
    else if (message->seat_id == 3)
    {
        statusLabel = ui->seatStatusLabel3;
    }
    else if (message->seat_id == 4)
    {
        statusLabel = ui->seatStatusLabel4;
    }
    else if (message->seat_id == 5)
    {
        statusLabel = ui->seatStatusLabel5;
    }


    if (statusLabel != nullptr)
    {
        if (message->occupied == true)
        {
            statusLabel->setText("사용 중");
        }
        else
        {
            if (message->has_belongings == true)
            {
                statusLabel->setText(
                    "자리 비움\n소지품 있음"
                );
            }
            else
            {
                statusLabel->setText("비어 있음");
            }
        }
    }
}


// =============================================================
// 패널티 처리
// =============================================================

void GuiMonitorNode::processPenalty(
    const std::vector<int>& seat_ids)
{
    if (seat_ids.empty())
    {
        return;
    }


    if (!process_penalty_client->service_is_ready())
    {
        RCLCPP_WARN(
            this->get_logger(),
            "패널티 처리 서비스가 준비되지 않았습니다."
        );

        return;
    }


    auto request =
        std::make_shared<
            qt_project::srv::ProcessPenalty::Request
        >();

    request->seat_ids = seat_ids;


    process_penalty_client->async_send_request(
        request,
        [this, seat_ids](
            rclcpp::Client<
                qt_project::srv::ProcessPenalty
            >::SharedFuture future)
        {
            auto response = future.get();


            if (response->success == true)
            {
                for (int seat_id : seat_ids)
                {
                    penalty_seat_ids.erase(
                        std::remove(
                            penalty_seat_ids.begin(),
                            penalty_seat_ids.end(),
                            seat_id
                        ),
                        penalty_seat_ids.end()
                    );
                }


                ui->penaltyListWidget->clear();


                for (int seat_id : penalty_seat_ids)
                {
                    ui->penaltyListWidget->addItem(
                        QString("%1번 좌석")
                            .arg(seat_id)
                    );
                }


                RCLCPP_INFO(
                    this->get_logger(),
                    "패널티 처리가 완료되었습니다."
                );
            }
            else
            {
                RCLCPP_WARN(
                    this->get_logger(),
                    "패널티 처리에 실패했습니다."
                );
            }
        }
    );
}


// =============================================================
// 순찰 경로 요청
// =============================================================

void GuiMonitorNode::requestPatrolRoute(
    const std::vector<int>& seat_ids)
{
    if (seat_ids.empty())
    {
        RCLCPP_WARN(
            this->get_logger(),
            "순찰 요청 좌석이 없습니다."
        );

        patrol_in_progress = false;
        patrol_countdown = 10;

        ui->patrolTimerLabel->setText(
            "다음 순찰: 10초"
        );

        return;
    }


    if (!route_client->service_is_ready())
    {
        RCLCPP_WARN(
            this->get_logger(),
            "순찰 경로 서비스가 준비되지 않았습니다."
        );

        patrol_in_progress = false;
        patrol_countdown = 10;

        ui->patrolTimerLabel->setText(
            "다음 순찰: 10초"
        );

        return;
    }


    auto request =
        std::make_shared<
            qt_project::srv::GetRoute::Request
        >();

    // 순찰 시작 순간에 확정된 좌석 목록
    request->seat_ids = seat_ids;


    RCLCPP_INFO(
        this->get_logger(),
        "순찰 경로 요청: 대상 좌석 %ld개",
        request->seat_ids.size()
    );


    for (int seat_id : request->seat_ids)
    {
        RCLCPP_INFO(
            this->get_logger(),
            "순찰 대상 좌석: %d",
            seat_id
        );
    }


    route_client->async_send_request(
        request,
        [this](
            rclcpp::Client<
                qt_project::srv::GetRoute
            >::SharedFuture future)
        {
            auto response = future.get();


            // =================================================
            // 경로 생성 실패
            // =================================================

            if (response->route.empty())
            {
                RCLCPP_WARN(
                    this->get_logger(),
                    "순찰 경로가 비어 있습니다."
                );

                patrol_route.clear();
                current_route_index = 0;
                patrol_in_progress = false;
                patrol_countdown = 10;

                ui->patrolTimerLabel->setText(
                    "다음 순찰: 10초"
                );

                return;
            }


            // =================================================
            // 경로 저장
            // =================================================

            patrol_route = response->route;
            current_route_index = 0;


            RCLCPP_INFO(
                this->get_logger(),
                "순찰 경로를 받았습니다."
            );


            for (int seat_id : patrol_route)
            {
                RCLCPP_INFO(
                    this->get_logger(),
                    "순찰 경로: %d번 좌석",
                    seat_id
                );
            }


            // =================================================
            // GUI 순찰 경로 표시
            // =================================================

            ui->routeListWidget->clear();


            for (int seat_id : patrol_route)
            {
                ui->routeListWidget->addItem(
                    QString("%1번 좌석")
                        .arg(seat_id)
                );
            }


            // =================================================
            // 첫 번째 좌석으로 이동
            // =================================================

            updateRobotPosition(
                patrol_route[current_route_index]
            );
        }
    );
}


// =============================================================
// 로봇 이동
// =============================================================

void GuiMonitorNode::updateRobotPosition(int seat_id)
{
    robot_position = seat_id;


    ui->robotPositionLabel->setText(
        QString("로봇 위치: %1번 좌석")
            .arg(robot_position)
    );


    QPushButton* seatButton = nullptr;


    if (seat_id == 1)
    {
        seatButton = ui->seatButton1;
    }
    else if (seat_id == 2)
    {
        seatButton = ui->seatButton2;
    }
    else if (seat_id == 3)
    {
        seatButton = ui->seatButton3;
    }
    else if (seat_id == 4)
    {
        seatButton = ui->seatButton4;
    }
    else if (seat_id == 5)
    {
        seatButton = ui->seatButton5;
    }


    if (seatButton == nullptr)
    {
        return;
    }


    QPoint targetPosition =
        seatButton->pos();


    // 기존 애니메이션이 있으면 중지
    if (robot_animation != nullptr)
    {
        robot_animation->stop();
        delete robot_animation;
        robot_animation = nullptr;
    }


    // 새로운 애니메이션 생성
    robot_animation =
        new QPropertyAnimation(
            ui->robotLabel,
            "pos",
            this
        );


    // 좌석까지 2초 동안 이동
    robot_animation->setDuration(2000);


    robot_animation->setStartValue(
        ui->robotLabel->pos()
    );


    robot_animation->setEndValue(
        targetPosition
    );


    // =========================================================
    // 이동 완료 후
    // =========================================================

    connect(
        robot_animation,
        &QPropertyAnimation::finished,
        this,
        [this, seat_id]()
        {
            if (!patrol_in_progress)
            {
                return;
            }


            // 현재 좌석의 실제 상태를 다시 확인
            if (isSeatStillAbsent(seat_id))
            {
                processPenalty({seat_id});
            }


            // 마지막 좌석인지 확인
            if (current_route_index >=
                static_cast<int>(
                    patrol_route.size()
                ) - 1)
            {
                RCLCPP_INFO(
                    this->get_logger(),
                    "모든 순찰 대상 확인 완료"
                );


                // 홈으로 복귀
                updateRobotHome();

                return;
            }


            // 다음 좌석
            current_route_index++;


            updateRobotPosition(
                patrol_route[current_route_index]
            );
        }
    );


    robot_animation->start();
}


// =============================================================
// 패널티 대상 좌석 Callback
// =============================================================

void GuiMonitorNode::penaltyCallback(
    const std_msgs::msg::Int32MultiArray::SharedPtr message)
{
    for (int seat_id : message->data)
    {
        setSeatButtonRed(seat_id);


        bool already_exists = false;


        for (int existing_id : penalty_seat_ids)
        {
            if (existing_id == seat_id)
            {
                already_exists = true;
                break;
            }
        }


        if (already_exists == false)
        {
            penalty_seat_ids.push_back(seat_id);
        }
    }


    ui->penaltyListWidget->clear();


    for (int seat_id : penalty_seat_ids)
    {
        ui->penaltyListWidget->addItem(
            QString("%1번 좌석")
                .arg(seat_id)
        );
    }
}


// =============================================================
// 좌석 버튼 빨간색
// =============================================================

void GuiMonitorNode::setSeatButtonRed(int seat_id)
{
    QPushButton* seatButton = nullptr;


    if (seat_id == 1)
    {
        seatButton = ui->seatButton1;
    }
    else if (seat_id == 2)
    {
        seatButton = ui->seatButton2;
    }
    else if (seat_id == 3)
    {
        seatButton = ui->seatButton3;
    }
    else if (seat_id == 4)
    {
        seatButton = ui->seatButton4;
    }
    else if (seat_id == 5)
    {
        seatButton = ui->seatButton5;
    }


    if (seatButton != nullptr)
    {
        seatButton->setStyleSheet(
            "background-color: red;"
        );
    }
}


// =============================================================
// 좌석 버튼 원상복구
// =============================================================

void GuiMonitorNode::setSeatButtonNormal(int seat_id)
{
    QPushButton* seatButton = nullptr;


    if (seat_id == 1)
    {
        seatButton = ui->seatButton1;
    }
    else if (seat_id == 2)
    {
        seatButton = ui->seatButton2;
    }
    else if (seat_id == 3)
    {
        seatButton = ui->seatButton3;
    }
    else if (seat_id == 4)
    {
        seatButton = ui->seatButton4;
    }
    else if (seat_id == 5)
    {
        seatButton = ui->seatButton5;
    }


    if (seatButton != nullptr)
    {
        seatButton->setStyleSheet("");
    }
}


// =============================================================
// 좌석 상태 변경 명령
// =============================================================

void GuiMonitorNode::sendSeatCommand(
    int seat_id,
    bool occupied,
    bool has_belongings)
{
    qt_project::msg::SeatCommand message;


    message.seat_id = seat_id;
    message.occupied = occupied;
    message.has_belongings = has_belongings;


    seat_command_publisher->publish(message);


    // =========================================================
    // 착석 또는 귀가
    //
    // 해당 좌석의 패널티/순찰 제외 상태를 초기화
    // =========================================================

    if (occupied == true ||
        has_belongings == false)
    {
        if (seat_id == 1)
        {
            setSeatButtonNormal(1);

            penalty_seat_ids.erase(
                std::remove(
                    penalty_seat_ids.begin(),
                    penalty_seat_ids.end(),
                    1
                ),
                penalty_seat_ids.end()
            );

            patrol_excluded_seat_ids.erase(
                std::remove(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    1
                ),
                patrol_excluded_seat_ids.end()
            );
        }
        else if (seat_id == 2)
        {
            setSeatButtonNormal(2);

            penalty_seat_ids.erase(
                std::remove(
                    penalty_seat_ids.begin(),
                    penalty_seat_ids.end(),
                    2
                ),
                penalty_seat_ids.end()
            );

            patrol_excluded_seat_ids.erase(
                std::remove(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    2
                ),
                patrol_excluded_seat_ids.end()
            );
        }
        else if (seat_id == 3)
        {
            setSeatButtonNormal(3);

            penalty_seat_ids.erase(
                std::remove(
                    penalty_seat_ids.begin(),
                    penalty_seat_ids.end(),
                    3
                ),
                penalty_seat_ids.end()
            );

            patrol_excluded_seat_ids.erase(
                std::remove(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    3
                ),
                patrol_excluded_seat_ids.end()
            );
        }
        else if (seat_id == 4)
        {
            setSeatButtonNormal(4);

            penalty_seat_ids.erase(
                std::remove(
                    penalty_seat_ids.begin(),
                    penalty_seat_ids.end(),
                    4
                ),
                penalty_seat_ids.end()
            );

            patrol_excluded_seat_ids.erase(
                std::remove(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    4
                ),
                patrol_excluded_seat_ids.end()
            );
        }
        else if (seat_id == 5)
        {
            setSeatButtonNormal(5);

            penalty_seat_ids.erase(
                std::remove(
                    penalty_seat_ids.begin(),
                    penalty_seat_ids.end(),
                    5
                ),
                penalty_seat_ids.end()
            );

            patrol_excluded_seat_ids.erase(
                std::remove(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    5
                ),
                patrol_excluded_seat_ids.end()
            );
        }


        // 패널티 목록 갱신
        ui->penaltyListWidget->clear();


        for (int id : penalty_seat_ids)
        {
            ui->penaltyListWidget->addItem(
                QString("%1번 좌석")
                    .arg(id)
            );
        }
    }
}


// =============================================================
// 현재 순찰 대상 가져오기
// =============================================================

std::vector<int>
GuiMonitorNode::getCurrentPatrolTargets()
{
    std::vector<int> patrol_targets;


    std::time_t current_time =
        std::time(nullptr);


    for (int seat_id = 1;
         seat_id <= 5;
         seat_id++)
    {
        // 이미 순찰 대상으로 판단된 좌석인지 확인
        bool already_excluded = false;


        if (seat_id == 1)
        {
            if (std::find(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    1
                ) != patrol_excluded_seat_ids.end())
            {
                already_excluded = true;
            }
        }
        else if (seat_id == 2)
        {
            if (std::find(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    2
                ) != patrol_excluded_seat_ids.end())
            {
                already_excluded = true;
            }
        }
        else if (seat_id == 3)
        {
            if (std::find(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    3
                ) != patrol_excluded_seat_ids.end())
            {
                already_excluded = true;
            }
        }
        else if (seat_id == 4)
        {
            if (std::find(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    4
                ) != patrol_excluded_seat_ids.end())
            {
                already_excluded = true;
            }
        }
        else if (seat_id == 5)
        {
            if (std::find(
                    patrol_excluded_seat_ids.begin(),
                    patrol_excluded_seat_ids.end(),
                    5
                ) != patrol_excluded_seat_ids.end())
            {
                already_excluded = true;
            }
        }


        if (already_excluded)
        {
            continue;
        }


        // =====================================================
        // 이석 + 소지품 있음 + 20초 이상
        // =====================================================

        if (seat_occupied[seat_id] == false &&
            seat_has_belongings[seat_id] == true &&
            seat_absence_start_time[seat_id] > 0)
        {
            int absence_time =
                static_cast<int>(
                    current_time -
                    seat_absence_start_time[seat_id]
                );


            if (absence_time >= 20)
            {
                patrol_targets.push_back(
                    seat_id
                );
            }
        }
    }


    return patrol_targets;
}


// =============================================================
// 좌석 현재 상태 재확인
// =============================================================

bool GuiMonitorNode::isSeatStillAbsent(
    int seat_id)
{
    if (seat_id < 1 ||
        seat_id > 5)
    {
        return false;
    }


    if (seat_occupied[seat_id] == false &&
        seat_has_belongings[seat_id] == true &&
        seat_absence_start_time[seat_id] > 0)
    {
        std::time_t current_time =
            std::time(nullptr);


        int absence_time =
            static_cast<int>(
                current_time -
                seat_absence_start_time[seat_id]
            );


        if (absence_time >= 20)
        {
            return true;
        }
    }


    return false;
}


// =============================================================
// 이석 시간 Label 업데이트
// =============================================================

void GuiMonitorNode::updateTimeLabels()
{
    std::time_t current_time =
        std::time(nullptr);


    for (int seat_id = 1;
         seat_id <= 5;
         seat_id++)
    {
        QLabel* label = nullptr;


        if (seat_id == 1)
        {
            label = ui->absenceTimerLabel1;
        }
        else if (seat_id == 2)
        {
            label = ui->absenceTimerLabel2;
        }
        else if (seat_id == 3)
        {
            label = ui->absenceTimerLabel3;
        }
        else if (seat_id == 4)
        {
            label = ui->absenceTimerLabel4;
        }
        else if (seat_id == 5)
        {
            label = ui->absenceTimerLabel5;
        }


        if (label == nullptr)
        {
            continue;
        }


        if (seat_occupied[seat_id] ||
            !seat_has_belongings[seat_id] ||
            seat_absence_start_time[seat_id] == 0)
        {
            label->setText(
                QString("%1번 이석: 0초")
                    .arg(seat_id)
            );
        }
        else
        {
            int absence_time =
                static_cast<int>(
                    current_time -
                    seat_absence_start_time[seat_id]
                );


            label->setText(
                QString("%1번 이석: %2초")
                    .arg(seat_id)
                    .arg(absence_time)
            );
        }
    }
}


// =============================================================
// 로봇 홈 복귀
// =============================================================

void GuiMonitorNode::updateRobotHome()
{
    robot_position = 1;


    ui->robotPositionLabel->setText(
        "로봇 처음 위치"
    );


    QPoint homePosition(290, 460);


    if (robot_animation != nullptr)
    {
        robot_animation->stop();
        delete robot_animation;
        robot_animation = nullptr;
    }


    robot_animation =
        new QPropertyAnimation(
            ui->robotLabel,
            "pos",
            this
        );


    // 홈까지 2초
    robot_animation->setDuration(2000);


    robot_animation->setStartValue(
        ui->robotLabel->pos()
    );


    robot_animation->setEndValue(
        homePosition
    );


    connect(
        robot_animation,
        &QPropertyAnimation::finished,
        this,
        [this]()
        {
            // 순찰 완료
            patrol_route.clear();
            current_route_index = 0;


            patrol_in_progress = false;


            // 다음 순찰은 10초 후
            patrol_countdown = 10;


            ui->patrolTimerLabel->setText(
                "다음 순찰: 10초"
            );


            RCLCPP_INFO(
                this->get_logger(),
                "순찰 완료. 다음 순찰까지 10초 대기"
            );
        }
    );


    robot_animation->start();
}