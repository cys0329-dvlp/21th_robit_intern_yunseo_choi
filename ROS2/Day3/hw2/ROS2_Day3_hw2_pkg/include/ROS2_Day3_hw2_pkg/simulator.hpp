#ifndef ROS2_DAY3_HW2_PKG_SIMULATOR_HPP
#define ROS2_DAY3_HW2_PKG_SIMULATOR_HPP

#include <QWidget>
#include <QString>

class SimulatorWidget : public QWidget
{
public:
    explicit SimulatorWidget(QWidget *parent = nullptr);

    void setTrafficLight(const QString &state);
    void setVehiclePosition(double position);
    void setVehicleSpeed(double speed);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString traffic_light_state_;
    double vehicle_position_;
    double vehicle_speed_;
};

#endif