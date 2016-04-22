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
    const char *ma = ba.data();
    input_file.open(ma);

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

void ArduinoRpm::wait(float seconds)
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) { }
}

void ArduinoRpm::serialReciver()
{

    QString input_converter;

    std::string to_file_string;
    //wait(0.1);
    //QThread::msleep(100); //100 microseconds delay
    int c = 0;
    char *dataBuffer;
    int size = serial->bytesAvailable();


    dataBuffer = new char[size + 1];
    serial->flush();

    c = serial->readLine(dataBuffer, size);
    //dataBuffer[c] = '\0';


    to_file_string = dataBuffer;
    input_converter = QString::fromStdString(to_file_string);

    if ((c >= 5) && (input_converter.toInt() < 9999)) {

        ui->lcdNumber->display(input_converter);
        rpmNeedle->setCurrentValue(input_converter.toInt());
        input_file << to_file_string;

    }

    qDebug() << c;
    //input_file << to_file_string;


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

void ArduinoRpm::on_actionExit_triggered()
{

}

void ArduinoRpm::on_actionSettings_triggered()
{
    SettingsDialog settingsDialog;
    settingsDialog.setModal(true);
    settingsDialog.exec();
}


