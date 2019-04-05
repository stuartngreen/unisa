// Program to capture order information and display all orders in a list. The program
// consists of a 'MainWindow' class which handles the GUI rendering and interaction, and
// 'Order' and 'OrderList' classes which create objects for the list to be displayed in
// the GUI.

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
