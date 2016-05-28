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
#include "splashdialog.h"

ArduinoRpm::ArduinoRpm(QWidget *parent,QString passed_serial) :
    QMainWindow(parent),
    ui(new Ui::ArduinoRpm), serialPortValue(passed_serial)
{

    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());


    /* QString supports UTF encoding while std::string
     * supports ascii encoding
     */

    //initialize the serial port
    SerialInitializer();
    drawGauge();

    /* get the current date from the system
     * and convert to the prefer format
     */
    date = QDate::currentDate();
    time = QTime::currentTime().toString("_hh_mm_ss");

    QString dt = date.toString("dd_MM_yyyy") + time + ".log";
    QByteArray ba = dt.toLatin1();
    const char *file_name = ba.data();
    input_file.open(file_name);

    /* setupUi() creates the actual instances of widgets
     * When "setupUi()" is called, all the UI elements that the user put on the form are created
     */

    connect(serial,SIGNAL(readyRead()), this, SLOT(serialReciver()));
    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(close()));

    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

    //Status bar
    statusMessage = "Connected on " + serialPortValue + " Port!";
    ui->statusBar->showMessage(statusMessage);

    connect(ui->actionLCD_Output,SIGNAL(toggled(bool)),
            this,SLOT(showFrame()));

    connect(ui->actionExit,SIGNAL(triggered(bool)),
            this,SLOT(close()));

}

void ArduinoRpm::showFrame() {

    if (ui->frame->isHidden())
        ui->frame->show();
    else
        ui->frame->hide();
}

ArduinoRpm::~ArduinoRpm()
{
    delete ui;
    serial->close();

}

void ArduinoRpm::drawGauge() {

    rpmGuage = new QcGaugeWidget;
    //external 'ring' position
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

    rpmGuage->addLabel(70)->setText("RPM");
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
}

void ArduinoRpm::serialReciver()
{

    QString input_converter;
    std::string to_file_string;
    time = QTime::currentTime().toString("  - hh:mm:ss:zzz");
    QByteArray ba = time.toLatin1();
    char *hd = ba.data();

    //if the whole line isn't available within the next 4 chars
    if (serial->bytesAvailable() < 4)
        return; //return from this call (wait for the next readyRead() signal)

    char dataBuffer[5];

    serial->readLine(dataBuffer,5);

    to_file_string = dataBuffer;
    input_converter = QString::fromStdString(to_file_string);


     if (input_converter.toInt() != 0) {
          ui->lcdNumber->display(input_converter);
          rpmNeedle->setCurrentValue(input_converter.toInt());
          input_file << "[ " << to_file_string << " ]" << hd << std::endl;
      }

     if (serial->bytesAvailable() > 0)
          QMetaObject::invokeMethod(this, "serialReciver", Qt::QueuedConnection);
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




