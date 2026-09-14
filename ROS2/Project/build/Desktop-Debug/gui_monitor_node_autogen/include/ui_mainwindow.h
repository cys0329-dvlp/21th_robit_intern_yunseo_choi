/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *seatButton1;
    QPushButton *seatButton2;
    QPushButton *seatButton3;
    QPushButton *seatButton4;
    QPushButton *seatButton5;
    QLabel *seatStatusLabel1;
    QLabel *seatStatusLabel2;
    QLabel *seatStatusLabel3;
    QLabel *seatStatusLabel4;
    QLabel *seatStatusLabel5;
    QLabel *penaltyTitleLabel;
    QListWidget *penaltyListWidget;
    QLabel *routeTitleLabel;
    QListWidget *routeListWidget;
    QLabel *robotPositionLabel;
    QPushButton *seat1SitButton;
    QPushButton *seat1LeaveButton;
    QPushButton *seat1GoHomeButton;
    QPushButton *seat2LeaveButton;
    QPushButton *seat2SitButton;
    QPushButton *seat3GoHomeButton;
    QPushButton *seat2GoHomeButton;
    QPushButton *seat3LeaveButton;
    QPushButton *seat3SitButton;
    QPushButton *seat4GoHomeButton;
    QPushButton *seat4LeaveButton;
    QPushButton *seat4SitButton;
    QPushButton *seat5GoHomeButton;
    QPushButton *seat5LeaveButton;
    QPushButton *seat5SitButton;
    QLabel *robotLabel;
    QLabel *patrolTimerLabel;
    QLabel *absenceTimerLabel1;
    QLabel *absenceTimerLabel2;
    QLabel *absenceTimerLabel3;
    QLabel *absenceTimerLabel4;
    QLabel *absenceTimerLabel5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        seatButton1 = new QPushButton(centralwidget);
        seatButton1->setObjectName("seatButton1");
        seatButton1->setGeometry(QRect(290, 210, 100, 70));
        seatButton2 = new QPushButton(centralwidget);
        seatButton2->setObjectName("seatButton2");
        seatButton2->setGeometry(QRect(510, 40, 100, 70));
        seatButton3 = new QPushButton(centralwidget);
        seatButton3->setObjectName("seatButton3");
        seatButton3->setGeometry(QRect(510, 400, 100, 70));
        seatButton4 = new QPushButton(centralwidget);
        seatButton4->setObjectName("seatButton4");
        seatButton4->setGeometry(QRect(700, 230, 100, 70));
        seatButton5 = new QPushButton(centralwidget);
        seatButton5->setObjectName("seatButton5");
        seatButton5->setGeometry(QRect(820, 230, 100, 70));
        seatStatusLabel1 = new QLabel(centralwidget);
        seatStatusLabel1->setObjectName("seatStatusLabel1");
        seatStatusLabel1->setGeometry(QRect(290, 280, 101, 41));
        seatStatusLabel2 = new QLabel(centralwidget);
        seatStatusLabel2->setObjectName("seatStatusLabel2");
        seatStatusLabel2->setGeometry(QRect(510, 110, 101, 41));
        seatStatusLabel3 = new QLabel(centralwidget);
        seatStatusLabel3->setObjectName("seatStatusLabel3");
        seatStatusLabel3->setGeometry(QRect(510, 470, 101, 41));
        seatStatusLabel4 = new QLabel(centralwidget);
        seatStatusLabel4->setObjectName("seatStatusLabel4");
        seatStatusLabel4->setGeometry(QRect(700, 300, 101, 41));
        seatStatusLabel5 = new QLabel(centralwidget);
        seatStatusLabel5->setObjectName("seatStatusLabel5");
        seatStatusLabel5->setGeometry(QRect(820, 300, 101, 41));
        penaltyTitleLabel = new QLabel(centralwidget);
        penaltyTitleLabel->setObjectName("penaltyTitleLabel");
        penaltyTitleLabel->setGeometry(QRect(20, 140, 111, 18));
        penaltyListWidget = new QListWidget(centralwidget);
        penaltyListWidget->setObjectName("penaltyListWidget");
        penaltyListWidget->setGeometry(QRect(20, 160, 161, 91));
        routeTitleLabel = new QLabel(centralwidget);
        routeTitleLabel->setObjectName("routeTitleLabel");
        routeTitleLabel->setGeometry(QRect(20, 290, 66, 18));
        routeListWidget = new QListWidget(centralwidget);
        routeListWidget->setObjectName("routeListWidget");
        routeListWidget->setGeometry(QRect(20, 310, 161, 91));
        robotPositionLabel = new QLabel(centralwidget);
        robotPositionLabel->setObjectName("robotPositionLabel");
        robotPositionLabel->setGeometry(QRect(20, 430, 141, 18));
        seat1SitButton = new QPushButton(centralwidget);
        seat1SitButton->setObjectName("seat1SitButton");
        seat1SitButton->setGeometry(QRect(290, 180, 88, 26));
        seat1LeaveButton = new QPushButton(centralwidget);
        seat1LeaveButton->setObjectName("seat1LeaveButton");
        seat1LeaveButton->setGeometry(QRect(290, 150, 88, 26));
        seat1GoHomeButton = new QPushButton(centralwidget);
        seat1GoHomeButton->setObjectName("seat1GoHomeButton");
        seat1GoHomeButton->setGeometry(QRect(290, 120, 88, 26));
        seat2LeaveButton = new QPushButton(centralwidget);
        seat2LeaveButton->setObjectName("seat2LeaveButton");
        seat2LeaveButton->setGeometry(QRect(610, 70, 88, 26));
        seat2SitButton = new QPushButton(centralwidget);
        seat2SitButton->setObjectName("seat2SitButton");
        seat2SitButton->setGeometry(QRect(610, 100, 88, 26));
        seat3GoHomeButton = new QPushButton(centralwidget);
        seat3GoHomeButton->setObjectName("seat3GoHomeButton");
        seat3GoHomeButton->setGeometry(QRect(420, 400, 88, 26));
        seat2GoHomeButton = new QPushButton(centralwidget);
        seat2GoHomeButton->setObjectName("seat2GoHomeButton");
        seat2GoHomeButton->setGeometry(QRect(610, 40, 88, 26));
        seat3LeaveButton = new QPushButton(centralwidget);
        seat3LeaveButton->setObjectName("seat3LeaveButton");
        seat3LeaveButton->setGeometry(QRect(420, 430, 88, 26));
        seat3SitButton = new QPushButton(centralwidget);
        seat3SitButton->setObjectName("seat3SitButton");
        seat3SitButton->setGeometry(QRect(420, 460, 88, 26));
        seat4GoHomeButton = new QPushButton(centralwidget);
        seat4GoHomeButton->setObjectName("seat4GoHomeButton");
        seat4GoHomeButton->setGeometry(QRect(610, 230, 88, 26));
        seat4LeaveButton = new QPushButton(centralwidget);
        seat4LeaveButton->setObjectName("seat4LeaveButton");
        seat4LeaveButton->setGeometry(QRect(610, 260, 88, 26));
        seat4SitButton = new QPushButton(centralwidget);
        seat4SitButton->setObjectName("seat4SitButton");
        seat4SitButton->setGeometry(QRect(610, 290, 88, 26));
        seat5GoHomeButton = new QPushButton(centralwidget);
        seat5GoHomeButton->setObjectName("seat5GoHomeButton");
        seat5GoHomeButton->setGeometry(QRect(920, 230, 88, 26));
        seat5LeaveButton = new QPushButton(centralwidget);
        seat5LeaveButton->setObjectName("seat5LeaveButton");
        seat5LeaveButton->setGeometry(QRect(920, 260, 88, 26));
        seat5SitButton = new QPushButton(centralwidget);
        seat5SitButton->setObjectName("seat5SitButton");
        seat5SitButton->setGeometry(QRect(920, 290, 88, 26));
        robotLabel = new QLabel(centralwidget);
        robotLabel->setObjectName("robotLabel");
        robotLabel->setGeometry(QRect(290, 440, 71, 41));
        patrolTimerLabel = new QLabel(centralwidget);
        patrolTimerLabel->setObjectName("patrolTimerLabel");
        patrolTimerLabel->setGeometry(QRect(290, 510, 131, 18));
        absenceTimerLabel1 = new QLabel(centralwidget);
        absenceTimerLabel1->setObjectName("absenceTimerLabel1");
        absenceTimerLabel1->setGeometry(QRect(290, 330, 121, 18));
        absenceTimerLabel2 = new QLabel(centralwidget);
        absenceTimerLabel2->setObjectName("absenceTimerLabel2");
        absenceTimerLabel2->setGeometry(QRect(510, 160, 141, 18));
        absenceTimerLabel3 = new QLabel(centralwidget);
        absenceTimerLabel3->setObjectName("absenceTimerLabel3");
        absenceTimerLabel3->setGeometry(QRect(510, 530, 111, 18));
        absenceTimerLabel4 = new QLabel(centralwidget);
        absenceTimerLabel4->setObjectName("absenceTimerLabel4");
        absenceTimerLabel4->setGeometry(QRect(700, 350, 101, 18));
        absenceTimerLabel5 = new QLabel(centralwidget);
        absenceTimerLabel5->setObjectName("absenceTimerLabel5");
        absenceTimerLabel5->setGeometry(QRect(830, 350, 101, 18));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Study Room Patrol Monitor", nullptr));
        seatButton1->setText(QCoreApplication::translate("MainWindow", "1\353\262\210 \354\242\214\354\204\235", nullptr));
        seatButton2->setText(QCoreApplication::translate("MainWindow", "2\353\262\210 \354\242\214\354\204\235", nullptr));
        seatButton3->setText(QCoreApplication::translate("MainWindow", "3\353\262\210 \354\242\214\354\204\235", nullptr));
        seatButton4->setText(QCoreApplication::translate("MainWindow", "4\353\262\210 \354\242\214\354\204\235", nullptr));
        seatButton5->setText(QCoreApplication::translate("MainWindow", "5\353\262\210 \354\242\214\354\204\235", nullptr));
        seatStatusLabel1->setText(QCoreApplication::translate("MainWindow", "\354\203\201\355\203\234 \355\231\225\354\235\270 \354\244\221", nullptr));
        seatStatusLabel2->setText(QCoreApplication::translate("MainWindow", "\354\203\201\355\203\234 \355\231\225\354\235\270 \354\244\221", nullptr));
        seatStatusLabel3->setText(QCoreApplication::translate("MainWindow", "\354\203\201\355\203\234 \355\231\225\354\235\270 \354\244\221", nullptr));
        seatStatusLabel4->setText(QCoreApplication::translate("MainWindow", "\354\203\201\355\203\234 \355\231\225\354\235\270 \354\244\221", nullptr));
        seatStatusLabel5->setText(QCoreApplication::translate("MainWindow", "\354\203\201\355\203\234 \355\231\225\354\235\270 \354\244\221", nullptr));
        penaltyTitleLabel->setText(QCoreApplication::translate("MainWindow", "\355\216\230\353\204\220\355\213\260 \353\214\200\354\203\201", nullptr));
        routeTitleLabel->setText(QCoreApplication::translate("MainWindow", "\354\210\234\354\260\260 \352\262\275\353\241\234", nullptr));
        robotPositionLabel->setText(QCoreApplication::translate("MainWindow", "\353\241\234\353\264\207 \354\234\204\354\271\230: 1\353\262\210 \354\242\214\354\204\235", nullptr));
        seat1SitButton->setText(QCoreApplication::translate("MainWindow", "\354\260\251\354\204\235", nullptr));
        seat1LeaveButton->setText(QCoreApplication::translate("MainWindow", "\354\235\264\354\204\235", nullptr));
        seat1GoHomeButton->setText(QCoreApplication::translate("MainWindow", "\352\267\200\352\260\200", nullptr));
        seat2LeaveButton->setText(QCoreApplication::translate("MainWindow", "\354\235\264\354\204\235", nullptr));
        seat2SitButton->setText(QCoreApplication::translate("MainWindow", "\354\260\251\354\204\235", nullptr));
        seat3GoHomeButton->setText(QCoreApplication::translate("MainWindow", "\352\267\200\352\260\200", nullptr));
        seat2GoHomeButton->setText(QCoreApplication::translate("MainWindow", "\352\267\200\352\260\200", nullptr));
        seat3LeaveButton->setText(QCoreApplication::translate("MainWindow", "\354\235\264\354\204\235", nullptr));
        seat3SitButton->setText(QCoreApplication::translate("MainWindow", "\354\260\251\354\204\235", nullptr));
        seat4GoHomeButton->setText(QCoreApplication::translate("MainWindow", "\352\267\200\352\260\200", nullptr));
        seat4LeaveButton->setText(QCoreApplication::translate("MainWindow", "\354\235\264\354\204\235", nullptr));
        seat4SitButton->setText(QCoreApplication::translate("MainWindow", "\354\260\251\354\204\235", nullptr));
        seat5GoHomeButton->setText(QCoreApplication::translate("MainWindow", "\352\267\200\352\260\200", nullptr));
        seat5LeaveButton->setText(QCoreApplication::translate("MainWindow", "\354\235\264\354\204\235", nullptr));
        seat5SitButton->setText(QCoreApplication::translate("MainWindow", "\354\260\251\354\204\235", nullptr));
        robotLabel->setText(QCoreApplication::translate("MainWindow", "----------------\n"
"|  ROBOT  |\n"
"----------------", nullptr));
        patrolTimerLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        absenceTimerLabel1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        absenceTimerLabel2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        absenceTimerLabel3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        absenceTimerLabel4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        absenceTimerLabel5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
