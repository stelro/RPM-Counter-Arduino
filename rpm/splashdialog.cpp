/*
 *  splashdialog.cpp - the first dialog shown with the start of the application
 *  used for selecting the available serila's port's by the user
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

#include "splashdialog.h"
#include "ui_splashdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(close()));

    //get all avaliable serial ports
    serialPorts = QSerialPortInfo::availablePorts();

    //list all avaliable serial ports
    foreach(QSerialPortInfo item, serialPorts) {
        ui->serialPortCombo->addItem(item.portName());
    }


    //when the connectbutton is pressed, send the selected
    //serial port to the main form
    //read more about signals/slots in the Qt Documentation
    connect(ui->connectButton,SIGNAL(released()),
            this,SLOT(sendDataRpm()));
}


SettingsDialog::~SettingsDialog()
{
    delete ui;
}


void SettingsDialog::sendDataRpm()
{
    /* rpmForm is the main form, if this method is called, hide this
     * (settings form) and show the main form with the rpm counter */

    rpmForm = new ArduinoRpm(this,ui->serialPortCombo->currentText());
    rpmForm->show();
    this->hide();
}
