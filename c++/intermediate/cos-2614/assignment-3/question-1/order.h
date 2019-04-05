// Interface file for class 'Order' which represents an order comprised of name, date added, quantity,
// price and total price. There is a:
//  - constructor which accepts values for all the members,
//  - destructor,
//  - toString() function which returns order data as a QString.

#ifndef ORDER_H
#define ORDER_H
#include <QDebug>
#include <QString>
#include <QDate>

class Order
{
public:
    Order(QString name, QDate dateAdded, int quantity, double price, double totalPrice);
    ~Order();
    QString toString() const;
private:
    QString m_Name;
    QDate m_DateAdded;
    int m_Quantity;
    double m_Price;
    double m_TotalPrice;
};

#endif // ORDER_H
