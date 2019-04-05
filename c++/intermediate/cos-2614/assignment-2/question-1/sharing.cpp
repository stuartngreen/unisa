// Implementation file for class 'Sharing'.
#include "sharing.h"

// Constructor for a shared booking that accepts TWO GUESTS in addition to the base class data members.
Sharing::Sharing(Person c, QDate a, QDate d, Person g1, Person g2)
    : Booking(c, a ,d), m_Guest1(g1), m_Guest2(g2)
{
}

// Returns a neatly formatted string comprised of the data members of the base class and derived class.
QString Sharing::toString()
{
    return QString("Guest #1:\t%1\nGuest #2:\t%2\n%3\nRate:\t\tR%4 pn")
            .arg(m_Guest1.toString())
            .arg(m_Guest2.toString())
            .arg(Booking::toString())
            .arg(QString::number(rate(), 'f', 2));
}

// Returns the total rate for a shared room, i.e. doubled for two guests.
double Sharing::rate() const
{
    return SHARING_PPPN * 2;
}
