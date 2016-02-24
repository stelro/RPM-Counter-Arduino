#-------------------------------------------------
#
# Project created by QtCreator 2016-02-23T23:01:57
#
#-------------------------------------------------

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpm
TEMPLATE = app


SOURCES += main.cpp\
        arduinorpm.cpp \
    settingsdialog.cpp

HEADERS  += arduinorpm.h \
    settingsdialog.h

FORMS    += arduinorpm.ui \
    settingsdialog.ui
