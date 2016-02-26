#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSerialPortInfo>
#include "arduinorpm.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();
private slots:
    void on_pushButton_2_clicked();
private:
    Ui::SettingsDialog *ui;
    ArduinoRpm rpmForm;

    QList<QSerialPortInfo> serialPorts;
    QList<QString> buadRatesList;
    QList<QString> dataBitsList;
    QList<QString> parityList;
    QList<QString> stopBitsList;
    QList<QString> flowControllList;

};

#endif // SETTINGSDIALOG_H
