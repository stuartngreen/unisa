// Semester 2: Assignment 2 Question 4
// Program to get module marks from the GetStudent process, calculate the student's
// average mark, and check whether the student graduates or not. Program also outputs
// the StudentList as an XML file on exit.

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
