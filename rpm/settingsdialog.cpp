#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(close()));


    serialPorts = QSerialPortInfo::availablePorts();

    foreach(QSerialPortInfo item, serialPorts) {
        ui->serialPortCombo->addItem(item.portName());
    }

    //Initialize the settings list
    buadRatesList << "Baud1200" << "Baud2400" << "Baud4800" << "Baud9600" << "Baud19200"
                  << "Baud38400" << "Baud57600" << "Baud115200" << "UnknownBaud";

    dataBitsList << "Data5" << "Data6" << "Data7" << "Data8" << "UnknownDataBits";
    parityList << "NoParity" << "EvenParity" << "OddParity" << "SpaceParity" <<
                  "MarkParity" << "UnknownParity";
    stopBitsList << "OneStop" << "OneAndHalfSto" << "TwoStop" << "UnknownStopBits";
    flowControllList << "NoFlowControl" << "HardwareControl" << "SoftwareControl" <<
                        "UnknownFlowControl";

    ui->baudRateCombo->addItems(buadRatesList);
    ui->baudRateCombo->setCurrentIndex(3);
    ui->dataBitsCombo->addItems(dataBitsList);
    ui->dataBitsCombo->setCurrentIndex(3);
    ui->parityCombo->addItems(parityList);
    ui->parityCombo->setCurrentIndex(0);
    ui->stopBitsCombo->addItems(stopBitsList);
    ui->stopBitsCombo->setCurrentIndex(0);
    ui->flowControlCombo->addItems(flowControllList);
    ui->flowControlCombo->setCurrentIndex(0);

    connect(ui->baudRateCombo,SIGNAL(currentIndexChanged(QString)),
            &rpmForm, SLOT(getBaudRate(QString)));



}


SettingsDialog::~SettingsDialog()
{
    delete ui;
}



void SettingsDialog::on_pushButton_2_clicked()
{
    rpmForm.show();
}
