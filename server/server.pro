#-------------------------------------------------
#
# Project created by QtCreator 2016-07-17T18:36:21
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp \
    sql.cpp

HEADERS  += server.h \
    sql.h

FORMS    += server.ui
