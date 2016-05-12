/********************************************************************************
** Form generated from reading UI file 'arduinorpm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINORPM_H
#define UI_ARDUINORPM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArduinoRpm
{
public:
    QAction *actionExit;
    QAction *actionLCD_Output;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuShow;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ArduinoRpm)
    {
        if (ArduinoRpm->objectName().isEmpty())
            ArduinoRpm->setObjectName(QStringLiteral("ArduinoRpm"));
        ArduinoRpm->setWindowModality(Qt::NonModal);
        ArduinoRpm->resize(582, 605);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        ArduinoRpm->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("Speed-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        ArduinoRpm->setWindowIcon(icon);
        ArduinoRpm->setStyleSheet(QLatin1String("#ArduinoRpm {\n"
"	background: #f5f4f4;\n"
"}\n"
"#pushButton {\n"
" background: #55ff55;\n"
"  background-image: -webkit-linear-gradient(top, #55ff55, #84f084);\n"
"  background-image: -moz-linear-gradient(top, #55ff55, #84f084);\n"
"  background-image: -ms-linear-gradient(top, #55ff55, #84f084);\n"
"  background-image: -o-linear-gradient(top, #55ff55, #84f084);\n"
"  background-image: linear-gradient(to bottom, #55ff55, #84f084);\n"
"  border-radius: 6px;\n"
"  font-family: Georgia;\n"
"  color: #4d4b4d;\n"
"  font-size: 16px;\n"
"  padding: 10px 20px 10px 20px;\n"
"  text-decoration: none;\n"
"}\n"
"\n"
"#pushButton:hover:!pressed {\n"
"  background: #03e803;\n"
"  background-image: -webkit-linear-gradient(top, #03e803, #0fdb0f);\n"
"  background-image: -moz-linear-gradient(top, #03e803, #0fdb0f);\n"
"  background-image: -ms-linear-gradient(top, #03e803, #0fdb0f);\n"
"  background-image: -o-linear-gradient(top, #03e803, #0fdb0f);\n"
"  background-image: linear-gradient(to bottom, #03e803, #0fdb0f);\n"
"  te"
                        "xt-decoration: none;\n"
"}\n"
"\n"
"#statusBar {\n"
"background: #373b41;\n"
"color: #ffffff;\n"
"}"));
        actionExit = new QAction(ArduinoRpm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLCD_Output = new QAction(ArduinoRpm);
        actionLCD_Output->setObjectName(QStringLiteral("actionLCD_Output"));
        actionLCD_Output->setCheckable(true);
        actionLCD_Output->setChecked(true);
        actionLCD_Output->setEnabled(true);
        centralWidget = new QWidget(ArduinoRpm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 490, 151, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Georgia"));
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        pushButton->setFont(font1);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 40, 531, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 490, 241, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(80, 0, 151, 41));
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(8);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 71, 24));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        ArduinoRpm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ArduinoRpm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 582, 21));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuShow = new QMenu(menuBar);
        menuShow->setObjectName(QStringLiteral("menuShow"));
        ArduinoRpm->setMenuBar(menuBar);
        statusBar = new QStatusBar(ArduinoRpm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        statusBar->setFont(font3);
        ArduinoRpm->setStatusBar(statusBar);

        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuShow->menuAction());
        menuSettings->addSeparator();
        menuSettings->addSeparator();
        menuSettings->addAction(actionExit);
        menuShow->addAction(actionLCD_Output);

        retranslateUi(ArduinoRpm);

        QMetaObject::connectSlotsByName(ArduinoRpm);
    } // setupUi

    void retranslateUi(QMainWindow *ArduinoRpm)
    {
        ArduinoRpm->setWindowTitle(QApplication::translate("ArduinoRpm", "RPM Counter", 0));
        actionExit->setText(QApplication::translate("ArduinoRpm", "Exit", 0));
        actionLCD_Output->setText(QApplication::translate("ArduinoRpm", "LCD Output", 0));
        pushButton->setText(QApplication::translate("ArduinoRpm", "Exit", 0));
        label->setText(QApplication::translate("ArduinoRpm", "RPM :", 0));
        menuSettings->setTitle(QApplication::translate("ArduinoRpm", "Home", 0));
        menuShow->setTitle(QApplication::translate("ArduinoRpm", "Show", 0));
    } // retranslateUi

};

namespace Ui {
    class ArduinoRpm: public Ui_ArduinoRpm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINORPM_H
