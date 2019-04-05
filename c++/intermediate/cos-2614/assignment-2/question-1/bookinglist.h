// Interface file for class 'BookingList' which is derived from QList and represents a list
// of pointers to bookings. There is:
//  - destructor which calls deleteAll();
//  - roomsAvailable(QDate) returns the number of rooms available on a provided date;
//  - vacancy(QDate, QDate) returns true if there is at least one room available for the dates
//    between the arrival and departure;
//  - addBooking(...) adds pointers to Booking objects to the BookingList;
//  - deleteAll() deletes all the pointed to objects and then clears the BookingList.

#ifndef BOOKINGLIST_H
#define BOOKINGLIST_H
#include <QList>
#include <QDate>
#include <QDebug>
#include "booking.h"
#include "single.h"
#include "sharing.h"
#include "person.h"

class BookingList : public QList<Booking*>
{
public:
    ~BookingList();
    int roomsAvailable(QDate d);
    bool vacancy(QDate a, QDate d);
    Booking* addBooking(Person c, QDate a, QDate d, Person* g1, Person* g2 = 0);
    void deleteAll();
    static const int NO_OF_ROOMS = 3;
};

#endif // BOOKINGLIST_H
