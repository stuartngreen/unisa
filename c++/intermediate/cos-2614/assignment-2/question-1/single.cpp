// Implementation file for class 'Single'.
#include "single.h"

// Constructor for a single booking that accepts ONE GUEST in addition to the base class data members.
Single::Single(Person c, QDate a, QDate d, Person g)
    : Booking(c, a, d), m_Guest(g)
{
}

// Returns a neatly formatted string comprised of the data members of the base class and derived class.
QString Single::toString()
{
    return QString("Guest:\t\t%1\n%2\nRate:\t\tR%3 pn")
            .arg(m_Guest.toString())
            .arg(Booking::toString())
            .arg(QString::number(rate(), 'f', 2));
}

// Returns the rate for a room with only one guest.
double Single::rate() const
{
    return SINGLE_PPPN;
}
