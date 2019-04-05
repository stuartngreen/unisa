// Interface file for class 'Vendor' that represents vendor name, email and
// whether the vendor is also the manufacturer. There is:
// - a default constructor;
// - a destructor;
// - a setDetails() function to set the name, email and manufacturer status;
// - a getName() function to return a supplier name;
// - a toString() function that returns vendor name and email.

#ifndef VENDOR_H
#define VENDOR_H

#include <QString>

class Vendor
{
public:
    Vendor();
    ~Vendor();
    void setDetails(QString name, QString email, bool isManufacturer);
    bool isManufacturer();
    QString getName();
    QString toString();
private:
    QString m_Name;
    QString m_Email;
    bool m_isManufacturer;
};

#endif // VENDOR_H
