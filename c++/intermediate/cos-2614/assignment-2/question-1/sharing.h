// Interface file for class 'Sharing', derived from class 'Booking', representing shared
// bookings made at a guest house, comprising of two guests, in addition to the base class
// members. There is a:
//  - constructor which accepts values for the data members;
//  - toString() functions to return the data in a formatted way;
//  - rate() function to return appropriate rate doubled (for two people).

#ifndef SHARING_H
#define SHARING_H
#include "booking.h"

class Sharing : public Booking
{
public:
    Sharing(Person c, QDate a, QDate d, Person g1, Person g2);
    QString toString();
    double rate() const;
private:
    Person m_Guest1;
    Person m_Guest2;
};

#endif // SHARING_H
