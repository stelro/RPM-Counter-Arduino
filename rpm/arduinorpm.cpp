/*
 *  arduinorpm.cpp - Main class , used to manage the serial input
 *  with all it's settings and connections, also render the main
 *  speedometer with the specified parameters.
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

#include "arduinorpm.h"
#include "ui_arduinorpm.h"
#include "settingsdialog.h"

ArduinoRpm::ArduinoRpm(QWidget *parent,QString passed_serial) :
    QMainWindow(parent),
    ui(new Ui::ArduinoRpm), serialPortValue(passed_serial)
{
    SerialInitializer();


    date = QDate::currentDate();
    QString time = QTime::currentTime().toString("_hh_mm");

    QString dt = date.toString("dd_MM_yyyy") + time  + ".log";
    QByteArray ba = dt.toLatin1();
    const char *file_name = ba.data();
    input_file.open(file_name);

    ui->setupUi(this);
    rpmGuage = new QcGaugeWidget;
    rpmGuage->addBackground(99);
    QcBackgroundItem *bkg1 = rpmGuage->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,Qt::black);
    bkg1->addColor(1.0,Qt::white);

    QcBackgroundItem *bkg2 = rpmGuage->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,Qt::black);
    bkg2->addColor(1.0,Qt::darkGray);

    //the dots values , not the numbers
    rpmGuage->addArc(55);
    rpmGuage->addDegrees(65)->setValueRange(0,10);
    rpmGuage->addColorBand(50);

    rpmGuage->addValues(80)->setValueRange(0,10);

    rpmGuage->addLabel(70)->setText("x1000RPM");
    QcLabelItem *lab = rpmGuage->addLabel(40);
    lab->setText("0");
    //Needle height
    rpmNeedle = rpmGuage->addNeedle(60);
    rpmNeedle->setLabel(lab);
    rpmNeedle->setColor(Qt::white);
    rpmNeedle->setValueRange(0,10000);
    rpmGuage->addBackground(7);
    rpmGuage->addGlass(88);
    ui->verticalLayout->addWidget(rpmGuage);



    connect(serial,SIGNAL(readyRead()), this, SLOT(serialReciver()));
    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(close()));

    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    //Status bar
    statusMessage = "Connected on " + serialPortValue + " Port!";
    ui->statusBar->showMessage(statusMessage);


}

ArduinoRpm::~ArduinoRpm()
{
    delete ui;
    serial->close();

}

void ArduinoRpm::serialReciver()
{

    QString input_converter;
    std::string to_file_string;

    int sizeFromInput = 0;
    char *dataBuffer;
    int bufferSize = serial->bytesAvailable();

    dataBuffer = new char[bufferSize + 1];
    serial->flush();
    sizeFromInput = serial->readLine(dataBuffer, size);


    to_file_string = dataBuffer;
    input_converter = QString::fromStdString(to_file_string);

    if ((sizeFromInput >= 5) && (input_converter.toInt() <= 9999)) {
        ui->lcdNumber->display(input_converter);
        rpmNeedle->setCurrentValue(input_converter.toInt());
        input_file << to_file_string;
    }

    delete dataBuffer;

}

void ArduinoRpm::SerialInitializer()
{
    serial = new QSerialPort(this);
    serial->setPortName(serialPortValue); //COM-port your Arduino is connected to
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud9600); //must be the same as your arduino-baudrate
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}




