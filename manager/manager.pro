#-------------------------------------------------
#
# Project created by QtCreator 2016-07-17T10:15:04
#
#-------------------------------------------------

QT       += core gui

QT       +=network

QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = manager
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    dialog.cpp

HEADERS  += widget.h \
    dialog.h

FORMS    += widget.ui \
    dialog.ui

