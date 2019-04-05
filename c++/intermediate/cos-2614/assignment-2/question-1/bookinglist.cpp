// Implementation file for class 'BookingList'.

#include "bookinglist.h"

// Destructor which calls deleteAll().
BookingList::~BookingList()
{
    qDebug() << "In list destructor...";
    deleteAll();
}

// Returns the number of rooms available on a provided date by checking the date against
// all the Booking objects in the list.
int BookingList::roomsAvailable(QDate d)
{
    int roomsAvailable = NO_OF_ROOMS;

    for (int i = 0; i < this->size(); i++)
    {
        if (this->at(i)->booked(d))
            roomsAvailable--;
    }

    return roomsAvailable;
}

// Checks whether there is at least one room available for all of the dates between arrival and
// departure by calling roomsAvailable() for each date. Also checks for validity of dates and range.
bool BookingList::vacancy(QDate a, QDate d)
{
    if (a.isValid() && d.isValid() && a < d)
    {
        while (a < d)
        {
            if (roomsAvailable(a) == 0)
                return false;
            a = a.addDays(1);
        }
        return true;
    }
    return false;
}

// Adds pointers to Booking objects to the BookingList and returns said pointer.
Booking* BookingList::addBooking(Person c, QDate a, QDate d, Person *g1, Person *g2)
{
    QTextStream cout(stdout);
    Booking* bookingPtr;

    if (vacancy(a, d))
    {
        // Check for null guest in order to call the correct derived class constructor.
        if (g2 == 0)
            bookingPtr = new Single(c, a, d, *g1);
        else
            bookingPtr = new Sharing(c, a, d, *g1, *g2);

        this->append(bookingPtr);
    }
    else
        bookingPtr = NULL;

    return bookingPtr;
}

// Deletes all the pointed to Booking objects and then clears the BookingList.
void BookingList::deleteAll()
{
    for (int i = 0; i < this->size(); i++)
    {
        qDebug() << "Deleting object" << i + 1;
        delete this->at(i);
    }

    qDebug() << "Clearing pointer list.";
    this->clear();
}
