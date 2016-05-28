/*
  *  arduinorpm.h - Main class , used to manage the serial input
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


#ifndef ARDUINORPM_H
#define ARDUINORPM_H

#include <QMainWindow>
#include <QSerialPort>
#include <QWidget>
#include <QtGui>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QSlider>
#include <QtWidgets>
#include <fstream>

#include "qcgaugewidget.h"

namespace Ui {
class ArduinoRpm;
}

class ArduinoRpm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArduinoRpm(QWidget *parent = 0,QString passed_serial = "/dev/ttyUSB0");
    ~ArduinoRpm();
public slots:
    void serialReciver();
    void SerialInitializer();
    void showFrame();
private:

    //The main User Interface
    Ui::ArduinoRpm *ui;

    //Serial Port input
    QSerialPort *serial;

    QVBoxLayout *main_layout;
    QSlider *slider;
    QLCDNumber *lcd;

    QcGaugeWidget *rpmGuage;
    QcNeedleItem *rpmNeedle;

    //variable to hold settings values
    QString serialPortValue;

    //status bar message
    QString statusMessage;

    std::ofstream input_file;
    QDate date;
    QString time;

    void drawGauge();
};

#endif // ARDUINORPM_H
