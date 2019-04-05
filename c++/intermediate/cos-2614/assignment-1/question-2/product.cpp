// Implementation file for class 'Product'.
#include "product.h"

// Default constructor.
Product::Product()
    : m_Name(""), m_Price(0)
{
}

// Overloaded constructor that accepts name and price values in that order.
Product::Product(QString name, double price)
    : m_Name(name), m_Price(price)
{
}

// Destructor.
Product::~Product()
{
}

// Function to set the name, email and manufacturer status.
void Product::setSupplier(QString name, QString email, bool isManufacturer)
{
    m_Supplier.setDetails(name, email, isManufacturer);
}

// Function to return the supplier name (if manufacturer is supplier) or "Unknown".
QString Product::getManufacturerName()
{
    bool isManufacturer = m_Supplier.isManufacturer();
    if (isManufacturer)
        return m_Supplier.getName();
    else
        return "Unknown";
}

// Function that returns product details, or product and supplier details based on
// a provided boolean value.
QString Product::toString(bool supplierDetails)
{
    QString productDetails = QString("Product Name: %1\nProduct Price: %2")
            .arg(m_Name)
            .arg(QString::number(m_Price, 'f', 2));

    if (supplierDetails)
        return productDetails + m_Supplier.toString();
    else
        return productDetails;
}
