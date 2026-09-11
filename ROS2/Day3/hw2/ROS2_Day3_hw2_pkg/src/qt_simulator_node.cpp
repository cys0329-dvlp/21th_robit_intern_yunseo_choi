#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/point.hpp"

#include "ROS2_Day3_hw2_pkg/simulator.hpp"

#include <QApplication>
#include <QPainter>
#include <QTimer>
#include <QFont>

#include <memory>
#include <string>

class QtSimulatorNode : public rclcpp::Node
{
public:
    QtSimulatorNode(SimulatorWidget *widget)
    : Node("qt_simulator"),
      widget_(widget)
    {
        light_subscriber_ =
            this->create_subscription<std_msgs::msg::String>(
                "traffic_light_state",
                10,
                std::bind(
                    &QtSimulatorNode::trafficLightCallback,
                    this,
                    std::placeholders::_1));

        vehicle_subscriber_ =
            this->create_subscription<geometry_msgs::msg::Point>(
                "vehicle_position",
                10,
                std::bind(
                    &QtSimulatorNode::vehicleCallback,
                    this,
                    std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Qt simulator node started");
    }

private:
    void trafficLightCallback(
        const std_msgs::msg::String::SharedPtr message)
    {
        widget_->setTrafficLight(
            QString::fromStdString(message->data));
    }

    void vehicleCallback(
        const geometry_msgs::msg::Point::SharedPtr message)
    {
        widget_->setVehiclePosition(message->x);
        widget_->setVehicleSpeed(message->z);
    }

    SimulatorWidget *widget_;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr
        light_subscriber_;

    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr
        vehicle_subscriber_;
};

SimulatorWidget::SimulatorWidget(QWidget *parent)
: QWidget(parent)
{
    traffic_light_state_ = "RED";
    vehicle_position_ = 0.0;
    vehicle_speed_ = 0.0;

    setMinimumSize(1000, 600);
    setWindowTitle("ROS2 Traffic Light Simulator");
}

void SimulatorWidget::setTrafficLight(const QString &state)
{
    traffic_light_state_ = state;
    update();
}

void SimulatorWidget::setVehiclePosition(double position)
{
    vehicle_position_ = position;
    update();
}

void SimulatorWidget::setVehicleSpeed(double speed)
{
    vehicle_speed_ = speed;
    update();
}

void SimulatorWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    // 배경
    painter.fillRect(rect(), Qt::white);

    QFont title_font;
    title_font.setPointSize(24);
    title_font.setBold(true);

    painter.setFont(title_font);
    painter.drawText(
        30,
        45,
        "ROS2 Traffic Light Simulator");

    // 도로
    painter.setBrush(Qt::lightGray);
    painter.drawRect(
        50,
        250,
        width() - 100,
        150);

    // 도로 가운데 선
    QPen road_line_pen;
    road_line_pen.setWidth(4);
    road_line_pen.setStyle(Qt::DashLine);

    painter.setPen(road_line_pen);

    painter.drawLine(
        50,
        325,
        width() - 50,
        325);

    // 신호등 기둥
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);

    painter.drawRect(120, 100, 100, 300);

    // 빨간불
    if (traffic_light_state_ == "RED")
    {
        painter.setBrush(Qt::red);
    }
    else
    {
        painter.setBrush(Qt::darkGray);
    }

    painter.drawEllipse(145, 120, 50, 50);

    // 초록불
    if (traffic_light_state_ == "GREEN")
    {
        painter.setBrush(Qt::green);
    }
    else
    {
        painter.setBrush(Qt::darkGray);
    }

    painter.drawEllipse(145, 190, 50, 50);

    // 노란불
    if (traffic_light_state_ == "YELLOW")
    {
        painter.setBrush(Qt::yellow);
    }
    else
    {
        painter.setBrush(Qt::darkGray);
    }

    painter.drawEllipse(145, 260, 50, 50);

    // 정지선
    QPen stop_line_pen;
    stop_line_pen.setWidth(6);

    painter.setPen(stop_line_pen);

    painter.drawLine(
        400,
        250,
        400,
        400);

    // 차량 위치를 Qt 화면 위치로 바꾼다.
    double start_x = 80.0;
    double road_length = width() - 160.0;

    double screen_x =
        start_x + (vehicle_position_ / 30.0) * road_length;

    if (screen_x > width() - 100)
    {
        screen_x = width() - 100;
    }

    // 차량
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::black);

    painter.drawRect(
        static_cast<int>(screen_x),
        300,
        70,
        35);

    // 차량 정보
    QFont info_font;
    info_font.setPointSize(16);

    painter.setFont(info_font);
    painter.setPen(Qt::black);

    QString light_text =
        "Traffic Light : " + traffic_light_state_;

    QString position_text =
        QString("Vehicle Position : %1")
            .arg(vehicle_position_, 0, 'f', 2);

    QString speed_text =
        QString("Vehicle Speed : %1")
            .arg(vehicle_speed_, 0, 'f', 2);

    painter.drawText(
        350,
        100,
        light_text);

    painter.drawText(
        350,
        140,
        position_text);

    painter.drawText(
        350,
        180,
        speed_text);

    // 현재 상태 설명
    QString state_description;

    if (traffic_light_state_ == "GREEN")
    {
        state_description = "GREEN : Vehicle is moving";
    }
    else if (traffic_light_state_ == "YELLOW")
    {
        state_description = "YELLOW : Vehicle is slowing down";
    }
    else
    {
        state_description = "RED : Vehicle is stopped";
    }

    painter.drawText(
        350,
        220,
        state_description);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    QApplication app(argc, argv);

    SimulatorWidget widget;

    auto node =
        std::make_shared<QtSimulatorNode>(&widget);

    widget.show();

    QTimer ros_timer;

    QObject::connect(
        &ros_timer,
        &QTimer::timeout,
        [&]()
        {
            rclcpp::spin_some(node);
        });

    ros_timer.start(10);

    int result = app.exec();

    rclcpp::shutdown();

    return result;
}