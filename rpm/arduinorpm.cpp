#include "arduinorpm.h"
#include "ui_arduinorpm.h"
#include "settingsdialog.h"

ArduinoRpm::ArduinoRpm(QWidget *parent,QString passed_serial) :
    QMainWindow(parent),
    ui(new Ui::ArduinoRpm), serialPortValue(passed_serial)
{
    /* QString supports UTF encoding while std::string
     * supports ascii encoding
     */


    //initialize the serial port
    SerialInitializer();


    /* get the current date from the system
     * and convert to the prefer format
     */

    date = QDate::currentDate();
    QString time = QTime::currentTime().toString("_hh_mm");

    QString dt = date.toString("dd_MM_yyyy") + time  + ".log";
    QByteArray ba = dt.toLatin1();
    const char *file_name = ba.data();
    input_file.open(file_name);

    /* setupUi() creates the actual instances of widgets
     * When "setupUi()" is called, all the UI elements that the user put on the form are created
     */

    ui->setupUi(this);


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

    //get the port size depending on bytes available to read
      qint64 bufferSize = serial->bytesAvailable();
    //int bufferSize = serial->bytesAvailable();

    //dataBuffer, get the data from serial port, bufferSize + 1 for the newline
    dataBuffer = new char[bufferSize + 1];

    //flush the port before read
    serial->flush();

    //This function reads a line of ASCII characters from the device, up to a maximum of
    //maxSize - 1 bytes, stores the characters in dataBuffer, and returns the number of bytes
    //read. if a line could not be read but no error ocurred, this function returns 0. if an
    //error occurs, this function returns the length of what could read or -1 if nothing was read.
    //bufferSize is the maxsize readline can read.

    sizeFromInput = serial->readLine(dataBuffer, bufferSize);

    //to_file_string, to write data in file
    to_file_string = dataBuffer;
    input_converter = QString::fromStdString(to_file_string);

    //
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




