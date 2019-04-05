// Interface file for class 'Booking', representing bookings made at a guest house, comprising
// of contact person, arrival date, and departure date. There is a:
//  - constructor which accepts values for the data members;
//  - destructor;
//  - toString() function to return the data in a formatted way;
//  - booked(QDate) function to check if the provided date falls between the booking dates;
//  - rate() function to return appropriate rate based on booking type (single or shared).

#ifndef BOOKING_H
#define BOOKING_H
#include <QDate>
#include <QString>
#include "person.h"

class Booking
{
public:
    Booking(Person c, QDate a, QDate d);
    virtual ~Booking();
    virtual QString toString();
    virtual double rate() const = 0;
    bool booked(QDate d) const;
    static const double SINGLE_PPPN = 650;
    static const double SHARING_PPPN = 400;
private:
    Person m_Contact;
    QDate m_ArrivalDate;
    QDate m_DepartureDate;
};

#endif // BOOKING_H
