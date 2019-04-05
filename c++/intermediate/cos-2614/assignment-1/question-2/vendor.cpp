// Implementation file for class 'Vendor'.
#include "vendor.h"

// Default constructor.
Vendor::Vendor() : m_Name(""), m_Email(""), m_isManufacturer(false)
{
}

// Destructor.
Vendor::~Vendor()
{
}

// Function to set the name, email and manufacturer status.
void Vendor::setDetails(QString name, QString email, bool isManufacturer)
{
    m_Name = name;
    m_Email = email;
    m_isManufacturer = isManufacturer;
}

// Function to return whether supplier is also manufacturer (bool).
bool Vendor::isManufacturer()
{
    return m_isManufacturer;
}

// Function to return a supplier name.
QString Vendor::getName()
{
    return m_Name;
}

// Function that returns vendor name and email.
QString Vendor::toString()
{
    QString supplierDetails = QString("\nSupplier Name: %1\nSupplier Email: %2")
            .arg(m_Name)
            .arg(m_Email);
    return supplierDetails;
}
