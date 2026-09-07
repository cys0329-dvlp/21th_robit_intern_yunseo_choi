#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void udp_read();

    QUdpSocket *text_socket = new QUdpSocket(this);

    ~MainWindow();

private slots:
    void on_sendBtn_clicked();

private:
    Ui::MainWindow *ui;
    QHostAddress ROBIT_IP = QHostAddress("172.100.0.183");
    QHostAddress ROBOT_IP = QHostAddress("172.100.6.53");

    uint16_t TEXT_PORT = 10004;

};


#endif // MAINWINDOW_H
