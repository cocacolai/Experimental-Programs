#-------------------------------------------------
#
# Project created by QtCreator 2014-06-10T13:46:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClassObjectToScreen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    person.cpp

HEADERS  += mainwindow.h \
    person.h \
    personTypes.h

FORMS    += mainwindow.ui

INCLUDEPATH += types.h
