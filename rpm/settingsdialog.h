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
    void sendDataRpm();
private:
    Ui::SettingsDialog *ui;
    ArduinoRpm *rpmForm;

    QList<QSerialPortInfo> serialPorts;

};

#endif // SETTINGSDIALOG_H
