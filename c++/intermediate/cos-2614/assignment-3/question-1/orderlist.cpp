// Implementation file for class 'OrderList'.

#include "orderlist.h"

// Constructor.
OrderList::OrderList()
{    
}

// Destructor.
OrderList::~OrderList()
{
    qDebug() << "Destroying OrderList...";
    qDeleteAll(m_OrderList);
}

// Function to append an order to the list.
void OrderList::addOrder(Order* order)
{
    m_OrderList.append(order);
}

// Function to return the whole list of orders as a string.
QString OrderList::toString() const
{
    QString str;

    for (int i = 0; i < m_OrderList.size(); i++)
    {
        str.append(m_OrderList[i]->toString());
        str.append("\n");
    }
    return str;
}
