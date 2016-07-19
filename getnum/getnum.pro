#-------------------------------------------------
#
# Project created by QtCreator 2016-07-16T13:58:57
#
#-------------------------------------------------

QT       += core gui

QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jiaohao
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    close.cpp

HEADERS  += widget.h \
    close.h

FORMS    += widget.ui \
    close.ui

RESOURCES += \
    er.qrc
