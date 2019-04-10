#-------------------------------------------------
#
# Project created by QtCreator 2018-08-10T10:14:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Music
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    musicmodel.cpp \
    currencydelegate.cpp

HEADERS  += mainwindow.h \
    musicmodel.h \
    currencydelegate.h
