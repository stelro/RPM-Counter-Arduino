#include "arduinorpm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArduinoRpm w;
    w.show();

    return a.exec();
}
