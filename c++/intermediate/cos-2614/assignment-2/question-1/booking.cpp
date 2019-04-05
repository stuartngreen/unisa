// Implementation file for class 'Booking'.
#include "booking.h"

// Constructor for the base class that accepts contact person, arrival date, and departure date.
Booking::Booking(Person c, QDate a, QDate d)
    : m_Contact(c), m_ArrivalDate(a), m_DepartureDate(d)
{
}

// Destructor.
Booking::~Booking()
{
}

// Return a neatly formatted string comprised of the base class data members.
QString Booking::toString()
{
    return QString("Contact:\t%1\nBooking:\t%2 - %3")
            .arg(m_Contact.toString())
            .arg(m_ArrivalDate.toString("yyyy/MM/dd"))
            .arg(m_DepartureDate.toString("yyyy/MM/dd"));
}

// Returns true if the provided date lies during the booking dates.
bool Booking::booked(QDate d) const
{
    return (d >= m_ArrivalDate && d < m_DepartureDate);
}
