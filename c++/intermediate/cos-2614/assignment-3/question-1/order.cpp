// Implementation file for class 'Order'.

#include "order.h"

// Constructor.
Order::Order(QString name, QDate dateAdded, int quantity, double price, double totalPrice)
    : m_Name(name), m_DateAdded(dateAdded), m_Quantity(quantity), m_Price(price), m_TotalPrice(totalPrice)
{
}

// Destructor.
Order::~Order()
{
    qDebug() << "Destroying Order...";
}

// Function to return the order data as a QString.
QString Order::toString() const
{
    return QString("%1, %2, [%3] @ R%4 | Total: R%5")
            .arg(m_Name)
            .arg(m_DateAdded.toString("dd.MM.yyyy"))
            .arg(QString::number(m_Quantity))
            .arg(QString::number(m_Price, 'f', 2))
            .arg(QString::number(m_TotalPrice, 'f', 2));
}
