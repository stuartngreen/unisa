#-------------------------------------------------
#
# Project created by QtCreator 2018-09-13T18:48:50
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProcessStudent
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    student.cpp \
    studentlist.cpp \
    xmloutput.cpp

HEADERS  += widget.h \
    student.h \
    studentlist.h \
    xmloutput.h
