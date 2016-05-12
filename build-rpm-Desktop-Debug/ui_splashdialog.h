/********************************************************************************
** Form generated from reading UI file 'splashdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHDIALOG_H
#define UI_SPLASHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *serialPortCombo;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *connectButton;
    QPushButton *pushButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(387, 115);
        QIcon icon;
        icon.addFile(QStringLiteral("Speed-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsDialog->setWindowIcon(icon);
        SettingsDialog->setStyleSheet(QLatin1String("#SettingsDialog {\n"
"	background: #f5f4f4\n"
"}\n"
"\n"
"#connectButton {\n"
"   background: #55ff55;\n"
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
"#connectButton:hover:!pressed {\n"
" background: #03e803;\n"
"  background-image: -webkit-linear-gradient(top, #03e803, #0fdb0f);\n"
"  background-image: -moz-linear-gradient(top, #03e803, #0fdb0f);\n"
"  background-image: -ms-linear-gradient(top, #03e803, #0fdb0f);\n"
"  background-image: -o-linear-gradient(top, #03e803, #0fdb0f);\n"
"  background-image: linear-gradient(to bottom, #03e803, #0f"
                        "db0f);\n"
"  text-decoration: none;\n"
"}\n"
"\n"
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
"  t"
                        "ext-decoration: none;\n"
"}"));
        layoutWidget = new QWidget(SettingsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 351, 29));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        serialPortCombo = new QComboBox(layoutWidget);
        serialPortCombo->setObjectName(QStringLiteral("serialPortCombo"));

        gridLayout->addWidget(serialPortCombo, 0, 1, 1, 1);

        layoutWidget1 = new QWidget(SettingsDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 60, 351, 46));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        connectButton = new QPushButton(layoutWidget1);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(connectButton, 0, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "RPM Counter", 0));
        label->setText(QApplication::translate("SettingsDialog", "Serial Port:", 0));
        connectButton->setText(QApplication::translate("SettingsDialog", "Connect", 0));
        pushButton->setText(QApplication::translate("SettingsDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHDIALOG_H
