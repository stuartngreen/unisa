// Interface file for class 'OrderList' which represents a list of Order objects. There is a:
//  - default constructor,
//  - destructor,
//  - addOrder(Order*) function which appends an Order to the list.
//  - toString() function to return the whole order list as a string.

#ifndef ORDERLIST_H
#define ORDERLIST_H
#include <QDebug>
#include <QList>
#include <QString>
#include "order.h"

class OrderList
{
public:
    OrderList();
    ~OrderList();
    void addOrder(Order* order);
    QString toString() const;
private:
    QList<Order*> m_OrderList;
};

#endif // ORDERLIST_H
