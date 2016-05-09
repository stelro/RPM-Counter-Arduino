#include "settingsdialog.h"
#include "ui_settingsdialog.h"

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
