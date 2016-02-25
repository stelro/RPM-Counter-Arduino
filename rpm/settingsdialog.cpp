#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(close()));

    QList<QSerialPortInfo> list;
    list = QSerialPortInfo::availablePorts();



    foreach(QSerialPortInfo item, list) {
        ui->comboBox2->addItem(item.portName());
    }


}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_comboBox_activated(const QString &arg1)
{

}
