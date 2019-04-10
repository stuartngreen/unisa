// Semester 2: Assignment 1 Question 1
// Program to capture staff member information from a GUI, save it to a list and output
// to a file.

#include <QApplication>
#include <QDebug>
#include "staffinput.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StaffInput widget;
    widget.show();

    return a.exec();
}
