/*
 *  settingsdialog.h
 *
 *  This file is a part of RPM Counter
 *  Copyright (C) 2016 KASTORIA Robotics Team
 *  Main Author, Stelmach Rostislav, stelmach.ro<at>gmail.com
 *  Main Contributors, Michail Alexandros Savvanis, michalsavv<at>gmail.com
 *  and Perlat Kociaj, perlatkotsiai<at>outlook.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
