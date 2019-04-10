// Semester 2: Assignment 2 Question 1
// Program to capture student module marks from a GUI and then output to the console.

#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
