#-------------------------------------------------
#
# Project created by QtCreator 2015-04-11T22:00:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    cbutton.cpp

HEADERS  += mainwindow.h \
    cbutton.h

FORMS    += mainwindow.ui

include(muparser/muparser.pri)

#unix|win32: LIBS += -L$$PWD/muparser_v2_2_4/lib/ -lmuparser

#INCLUDEPATH += $$PWD/muparser_v2_2_4/include
#DEPENDPATH += $$PWD/muparser_v2_2_4/include
