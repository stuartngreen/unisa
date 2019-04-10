// Semester 2: Assignment 1 Question 3
// Program to capture music item information from a GUI, and add it to a custom model
// viewed in a QTableView.

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
