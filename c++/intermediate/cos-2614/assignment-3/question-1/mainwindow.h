// Header file for class 'MainWindow' which builds the GUI and handles the interaction between
// elements. There is a:
//  - constructor which builds the GUI,
//  - createMenu() which builds and returns the main menu,
//  - createFormLayout() which builds and returns the layout for the 'Add Order' form,
//  - setStackedIndex(int) function to set the index of the QStackedWidget;
//  - setTotalPrice() SLOT which sets the value of total price when modifying the unit price or quantity,
//  - addOrder() function which captures the values from the form and adds Orders to the OrderList.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QStackedWidget>
#include <QMenuBar>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QMessageBox>
#include "orderlist.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
    QMenu* createMenu();
    QVBoxLayout* createFormLayout();
    void setStackedIndex(int i) const;

public slots:
    void setTotalPrice();
    void addOrder();
    void goToPageOne();
    void goToPageTwo();
    void goToPageThree();

private:
    QStackedWidget* m_StackedWidget;
    QAction* m_AddOrderAction;
    QAction* m_ViewOrdersAction;
    QLineEdit* m_NameInput;
    QDateEdit* m_DateAddedInput;
    QSpinBox* m_QuantityInput;
    QDoubleSpinBox* m_PriceInput;
    QLineEdit* m_TotalPriceInput;
    QPushButton* m_OkButton;
    QPushButton* m_CancelButton;
    QTextEdit* m_TextEdit;
    OrderList m_OrderList;
};

#endif // MAINWINDOW_H
