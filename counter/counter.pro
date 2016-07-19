#-------------------------------------------------
#
# Project created by QtCreator 2016-07-16T16:51:02
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = counter
TEMPLATE = app


SOURCES += \
    signin.cpp \
    counter.cpp \
    main.cpp \
    close.cpp \
    evaluate.cpp \
    send.cpp \
    config.cpp

HEADERS  += \
    signin.h \
    counter.h \
    close.h \
    evaluate.h \
    send.h \
    config.h

FORMS    += \
    signin.ui \
    counter.ui \
    close.ui \
    evaluate.ui
