#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->verticalSlider, &QSlider::valueChanged, this, &MainWindow::slot_valueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Right_clicked()
{
    if(onoff_flag == 1)
    {
        ui->textBrowser->setText("우회전");
        ui->Status->setText("Moving");
    }
    else
    {
        ui->Status->setText("can't move");
    }
}

void MainWindow::on_Forward_clicked()
{
    if(onoff_flag == 1)
    {
        ui->textBrowser->setText("직진");
        ui->Status->setText("Moving");
    }
    else
    {
        ui->Status->setText("can't move");
    }
}


void MainWindow::on_Backward_clicked()
{
    if(onoff_flag == 1)
    {
        ui->textBrowser->setText("후진");
        ui->Status->setText("Moving");
    }
    else
    {
        ui->Status->setText("can't move");
    }
}


void MainWindow::on_Left_clicked()
{
    if(onoff_flag == 1)
    {
        ui->textBrowser->setText("좌회전");
        ui->Status->setText("Moving");
    }
    else
    {
        ui->Status->setText("can't move");
    }
}

void MainWindow::on_Stop_clicked()
{
    if(onoff_flag == 1)
    {
        ui->textBrowser->setText("정지");
        ui->Status->setText("stopped");
    }
    else
    {
        ui->Status->setText("can't move");
    }
}

void MainWindow::on_Main_clicked()
{
    if(onoff_flag == 0)
    {
        ui->Status->setText("ON");
        onoff_flag = 1;
    }
    else
    {
        ui->Status->setText("OFF");
        onoff_flag = 0;
    }
}
void MainWindow::slot_valueChanged(int value)
{
    QString strVal = QString("%1").arg(value);
    ui->textBrowser_2->setText(strVal);
}

