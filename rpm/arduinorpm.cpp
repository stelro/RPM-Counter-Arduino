#include "arduinorpm.h"
#include "ui_arduinorpm.h"
#include "settingsdialog.h"

ArduinoRpm::ArduinoRpm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArduinoRpm)
{

    ui->setupUi(this);

    SerialInitializer();

    rpmGuage = new QcGaugeWidget;
    rpmGuage->addBackground(99);
    QcBackgroundItem *bkg1 = rpmGuage->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,Qt::black);
    bkg1->addColor(1.0,Qt::white);

    QcBackgroundItem *bkg2 = rpmGuage->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,Qt::gray);
    bkg2->addColor(1.0,Qt::darkGray);

    //the dots values , not the numbers
    rpmGuage->addArc(55);
    rpmGuage->addDegrees(65)->setValueRange(0,100);
    rpmGuage->addColorBand(50);

    rpmGuage->addValues(80)->setValueRange(0,100);

    rpmGuage->addLabel(70)->setText("RPM");
    QcLabelItem *lab = rpmGuage->addLabel(40);
    lab->setText("0");
    //Needle height
    rpmNeedle = rpmGuage->addNeedle(60);
    rpmNeedle->setLabel(lab);
    rpmNeedle->setColor(Qt::white);
    rpmNeedle->setValueRange(0,100);
    rpmGuage->addBackground(7);
    rpmGuage->addGlass(88);
    ui->verticalLayout->addWidget(rpmGuage);


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
    rpmNeedle->setCurrentValue(input.toInt() / 10);

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



