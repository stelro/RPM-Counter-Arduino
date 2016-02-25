/********************************************************************************
** Form generated from reading UI file 'arduinorpm.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINORPM_H
#define UI_ARDUINORPM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArduinoRpm
{
public:
    QAction *actionSettings;
    QAction *actionExit;
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ArduinoRpm)
    {
        if (ArduinoRpm->objectName().isEmpty())
            ArduinoRpm->setObjectName(QStringLiteral("ArduinoRpm"));
        ArduinoRpm->resize(719, 523);
        actionSettings = new QAction(ArduinoRpm);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionExit = new QAction(ArduinoRpm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(ArduinoRpm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 30, 151, 41));
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(8);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 80, 151, 26));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 0, 57, 24));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(170, 0, 531, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ArduinoRpm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ArduinoRpm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 719, 23));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        ArduinoRpm->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ArduinoRpm);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ArduinoRpm->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ArduinoRpm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ArduinoRpm->setStatusBar(statusBar);

        menuBar->addAction(menuSettings->menuAction());
        menuSettings->addSeparator();
        menuSettings->addAction(actionSettings);
        menuSettings->addSeparator();
        menuSettings->addAction(actionExit);
        mainToolBar->addAction(actionSettings);

        retranslateUi(ArduinoRpm);

        QMetaObject::connectSlotsByName(ArduinoRpm);
    } // setupUi

    void retranslateUi(QMainWindow *ArduinoRpm)
    {
        ArduinoRpm->setWindowTitle(QApplication::translate("ArduinoRpm", "ArduinoRpm", 0));
        actionSettings->setText(QApplication::translate("ArduinoRpm", "Settings", 0));
        actionExit->setText(QApplication::translate("ArduinoRpm", "Exit", 0));
        pushButton->setText(QApplication::translate("ArduinoRpm", "Exit", 0));
        label->setText(QApplication::translate("ArduinoRpm", "RPM :", 0));
        menuSettings->setTitle(QApplication::translate("ArduinoRpm", "HOME", 0));
    } // retranslateUi

};

namespace Ui {
    class ArduinoRpm: public Ui_ArduinoRpm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINORPM_H
