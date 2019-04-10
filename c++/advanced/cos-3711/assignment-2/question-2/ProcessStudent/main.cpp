// Semester 2: Assignment 2 Question 2
// Program to start the GetStudent process and display the output.

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
