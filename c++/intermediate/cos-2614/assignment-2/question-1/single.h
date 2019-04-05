// Interface file for class 'Single', derived from class 'Booking', representing single
// bookings made at a guest house, comprising of one guest, in addition to the base class
// members. There is a:
//  - constructor which accepts values for the data members;
//  - toString() functions to return the data in a formatted way;
//  - rate() function to return appropriate rate.

#ifndef SINGLE_H
#define SINGLE_H
#include "booking.h"

class Single : public Booking
{
public:
    Single(Person c, QDate a, QDate d, Person g);
    QString toString();
    double rate() const;
private:
    Person m_Guest;
};

#endif // SINGLE_H
