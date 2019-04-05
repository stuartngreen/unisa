// Interface file for class 'Product' that represents product name, price
// and vendor details. There is:
// - a default constructor;
// - an overloaded constructor that accepts name and price values in that order;
// - a destructor;
// - a setSupplier() function to set the name, email and manufacturer status;
// - a getManufacturerName() function to return a supplier name or "Unknown";
// - a toString() function that returns product details, or product and supplier
//   details based on a provided boolean value.
// This class also uses an instance of the Vendor class for supplier details.

#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include "vendor.h"

class Product
{
public:
    Product();
    Product(QString name, double price);
    ~Product();
    void setSupplier(QString name, QString email, bool isManufacturer);
    QString getManufacturerName();
    QString toString(bool supplierDetails);
private:
    QString m_Name;
    double m_Price;
    Vendor m_Supplier;
};

#endif // PRODUCT_H
