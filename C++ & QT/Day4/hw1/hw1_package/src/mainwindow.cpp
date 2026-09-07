#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QUdpSocket>
#include <QNetworkDatagram>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "1. 프로그램 시작";
    if(text_socket->bind(QHostAddress::Any, TEXT_PORT, QUdpSocket::ShareAddress))
    {
        qDebug() << "2. bind 성공";

        connect(text_socket, &QUdpSocket::readyRead, this, &MainWindow::udp_read);

        qDebug() << "3. connect 성공";

    } else {
        qDebug() << "bind 에러" << text_socket->errorString();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendBtn_clicked()
{
    QString message = ui->plainTextEdit->toPlainText();
    QByteArray data = message.toUtf8();

    // 상대방 IP와 포트로 데이터 전송
    text_socket->writeDatagram(data, ROBOT_IP, TEXT_PORT);

    qint64 sentBytes = text_socket->writeDatagram(data, ROBOT_IP, TEXT_PORT);
    if (sentBytes == -1) {
        qDebug() << "전송 실패 에러:" << text_socket->errorString();
    } else {
        qDebug() << "전송 성공";
    }

    ui->plainTextEdit->clear(); // 입력창 비우기
}

void MainWindow::udp_read() {
    qDebug() << "4. UDP READ";
    while (text_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram =
            text_socket->receiveDatagram();

        QByteArray data = datagram.data();
        QHostAddress senderAddress =
            datagram.senderAddress();
        quint16 senderPort =
            datagram.senderPort();

        // QByteArray를 QString(텍스트)으로 변환
        QString message = QString::fromUtf8(data);

        // 상대방 IP 주소를 문자열로 변환
        QString senderIpStr = senderAddress.toString();

        // UI에 상대방 정보와 메시지 출력
        ui->textEdit->append(QString("%1")
                                 .arg(message));
    }
}
