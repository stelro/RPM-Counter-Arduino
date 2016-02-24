#include "arduinorpm.h"
#include "ui_arduinorpm.h"
#include "settingsdialog.h"

ArduinoRpm::ArduinoRpm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArduinoRpm)
{

    ui->setupUi(this);

    SerialInitializer();


    connect(serial,SIGNAL(readyRead()), this, SLOT(serialReciver()));
    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(close()));




    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);


}

ArduinoRpm::~ArduinoRpm()
{
    delete ui;
    serial->close();
}

void ArduinoRpm::serialReciver()
{
    QByteArray byteArray;
    byteArray = serial->readAll();
    QString input = QString(byteArray);

    ui->lcdNumber->display(input);
    ui->dial->setValue(input.toInt());
}

void ArduinoRpm::SerialInitializer()
{
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyUSB0"); //COM-port your Arduino is connected to
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud9600); //must be the same as your arduino-baudrate
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}

void ArduinoRpm::on_actionExit_triggered()
{

}

void ArduinoRpm::on_actionSettings_triggered()
{
    SettingsDialog settingsDialog;
    settingsDialog.setModal(true);
    settingsDialog.exec();
}

void ArduinoRpm::serialTransmiter()
{

    QByteArray dayArray;
    dayArray[0]=2;
    this->serial->write(dayArray);

}

void ArduinoRpm::on_lightButton_clicked()
{
    serialTransmiter();
}
