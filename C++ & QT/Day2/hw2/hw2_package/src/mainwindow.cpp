#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 입력창 추가 버튼
void MainWindow::on_pushButton_4_clicked()
{
    QLineEdit *newBox = new QLineEdit(ui->containerWidget);
    ui->verticalLayout->addWidget(newBox);
    inputBoxes.push_back(newBox);
}

// 등록 버튼
void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "등록 버튼 눌림, inputBoxes 개수:" << inputBoxes.size();
    for (QLineEdit *box : inputBoxes) {
        if (!box->text().isEmpty()) {
            todoQueue.enqueue(box->text());
        }
    }

    clearInputBoxes();
    updateDisplay();
}

// 완료 버튼
void MainWindow::on_pushButton_2_clicked()
{
    if (!todoQueue.isEmpty()) {
        todoQueue.dequeue();
    }
    updateDisplay();
}

// 입력창들 제거 및 벡터 비우기
void MainWindow::clearInputBoxes()
{
    for (QLineEdit *box : inputBoxes) {
        ui->verticalLayout->removeWidget(box);
        box->hide();          // 이 줄 추가 - 즉시 화면에서 숨김
        box->deleteLater();   // 실제 메모리 해제는 나중에
    }
    inputBoxes.clear();
}

// 현재 할 일 + 리스트 갱신
void MainWindow::updateDisplay()
{
    if (todoQueue.isEmpty()) {
        ui->label->setText("오늘 할 일 끝!");
        ui->pushButton_2->setEnabled(false);
    } else {
        ui->label->setText(todoQueue.head());
        ui->pushButton_2->setEnabled(true);
    }

    ui->todolistWidget->clear();
    for (const QString &item : todoQueue) {
        ui->todolistWidget->addItem(item);
    }
}
