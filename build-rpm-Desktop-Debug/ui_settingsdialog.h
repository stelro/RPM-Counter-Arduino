/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QComboBox *serialPortCombo;
    QLabel *label_5;
    QLabel *label_2;
    QComboBox *baudRateCombo;
    QComboBox *stopBitsCombo;
    QComboBox *dataBitsCombo;
    QComboBox *parityCombo;
    QLabel *label_6;
    QComboBox *flowControlCombo;
    QLabel *label_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(375, 232);
        layoutWidget = new QWidget(SettingsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(23, 23, 241, 194));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 2);

        serialPortCombo = new QComboBox(layoutWidget);
        serialPortCombo->setObjectName(QStringLiteral("serialPortCombo"));

        gridLayout->addWidget(serialPortCombo, 2, 2, 1, 2);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 2);

        baudRateCombo = new QComboBox(layoutWidget);
        baudRateCombo->setObjectName(QStringLiteral("baudRateCombo"));

        gridLayout->addWidget(baudRateCombo, 4, 2, 1, 2);

        stopBitsCombo = new QComboBox(layoutWidget);
        stopBitsCombo->setObjectName(QStringLiteral("stopBitsCombo"));

        gridLayout->addWidget(stopBitsCombo, 3, 2, 1, 2);

        dataBitsCombo = new QComboBox(layoutWidget);
        dataBitsCombo->setObjectName(QStringLiteral("dataBitsCombo"));

        gridLayout->addWidget(dataBitsCombo, 1, 2, 1, 2);

        parityCombo = new QComboBox(layoutWidget);
        parityCombo->setObjectName(QStringLiteral("parityCombo"));

        gridLayout->addWidget(parityCombo, 0, 2, 1, 2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 2);

        flowControlCombo = new QComboBox(layoutWidget);
        flowControlCombo->setObjectName(QStringLiteral("flowControlCombo"));

        gridLayout->addWidget(flowControlCombo, 5, 2, 1, 2);

        label_7 = new QLabel(SettingsDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(300, 110, 67, 17));
        widget = new QWidget(SettingsDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(270, 20, 87, 60));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Dialog", 0));
        label_4->setText(QApplication::translate("SettingsDialog", "Parity:", 0));
        label_3->setText(QApplication::translate("SettingsDialog", "Data Bits:", 0));
        label->setText(QApplication::translate("SettingsDialog", "Serial Port:", 0));
        label_5->setText(QApplication::translate("SettingsDialog", "Stop Bits:", 0));
        label_2->setText(QApplication::translate("SettingsDialog", "Baud Rate:", 0));
        label_6->setText(QApplication::translate("SettingsDialog", "Flow Control:", 0));
        label_7->setText(QApplication::translate("SettingsDialog", "TextLabel", 0));
        pushButton_2->setText(QApplication::translate("SettingsDialog", "Connect", 0));
        pushButton->setText(QApplication::translate("SettingsDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
