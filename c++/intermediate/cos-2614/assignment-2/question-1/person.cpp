// Implementation file for class 'Person'.

#include "person.h"

// Constructor that accepts and initialises name, contact number, and email address.
Person::Person(QString n, QString c, QString e)
    : m_Name(n), m_ContactNo(c), m_Email(e)
{
}

// Returns a neatly formatted string comprised of the data members.
QString Person::toString() const
{
    return QString("%1, %2, %3")
            .arg(m_Name)
            .arg(m_ContactNo)
            .arg(m_Email);
}
