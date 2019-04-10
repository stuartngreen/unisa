// Semester 2: Assignment 1 Question 2
// Program to capture staff member information from a GUI, save it to a list and output
// to a file using reflective programming, QMetaObject and Q_PROPERTY.

#include <QApplication>
#include "staffinput.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StaffInput widget;
    widget.show();

    return a.exec();
}
