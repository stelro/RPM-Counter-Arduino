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

    connect(ui->connectButton,SIGNAL(released()),
            this,SLOT(sendDataRpm()));



}


SettingsDialog::~SettingsDialog()
{
    delete ui;
}


void SettingsDialog::sendDataRpm()
{
    rpmForm = new ArduinoRpm(this,ui->serialPortCombo->currentText());
    rpmForm->show();
    this->hide();
}
