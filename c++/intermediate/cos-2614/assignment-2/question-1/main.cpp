// Semester 1: Assignment 2 Question 1
// Program to test the classes to be used in an application for recording the bookings
// at a guest house.

#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include "person.h"
#include "booking.h"
#include "bookinglist.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Testing Program\n===============\n" << endl;

    // Create some Person objects.
    Person g1("Andrew", "0820102424", "andrew@gmail.com");
    Person g2("Barbara", "0820105353", "barbara@gmail.com");
    Person g3("Chris", "0820106565", "chris@gmail.com");
    Person g4("Danielle", "0820101515", "danielle@gmail.com");
    Person g5("Eric", "0820108989", "eric@gmail.com");

    // Create a list.
    BookingList myList;

    // Output some notes.
    cout << "There are 3 rooms in the guesthouse." << endl;
    cout << "A single booking costs R650.00 pppn." << endl;
    cout << "A shared booking costs R400.00 pppn, i.e. R800.00 in total." << endl;

    // Output list size.
    cout << "\nStarting list size: " << myList.size() << endl;

    // Add a booking with an invalid date.
    cout << "\n>>> Trying to add a booking with an invalid date:" << endl;
    Booking* bookingPtr = myList.addBooking(g1, QDate(2018,1,45), QDate(2018,2,1), &g2);
    if (bookingPtr == NULL)
        cout << "Please input valid dates for your booking." << endl;

    // Add a booking with an invalid date range.
    cout << "\n>>> Trying to add a booking with an invalid date range:" << endl;
    bookingPtr = myList.addBooking(g1, QDate(2018,2,1), QDate(2018,1,1), &g2, &g1);
    if (bookingPtr == NULL)
        cout << "Please input a valid date range for your booking." << endl;

    // Output list size.
    cout << "\nCurrent list size: " << myList.size() << endl;

    // Adding 5 valid bookings, where 3 have overlapping dates.
    cout << "\n>>> Adding 5 valid bookings, where 3 have overlapping dates:" << endl;
    myList.addBooking(g1, QDate(2018,3,1), QDate(2018,3,10), &g1);
    myList.addBooking(g2, QDate(2018,3,5), QDate(2018,3,15), &g2, &g3);
    myList.addBooking(g3, QDate(2018,3,7), QDate(2018,3,20), &g3, &g4);
    myList.addBooking(g4, QDate(2018,4,1), QDate(2018,4,10), &g4);
    myList.addBooking(g5, QDate(2018,5,1), QDate(2018,5,10), &g5, &g1);

    // Output list size.
    cout << "\nCurrent list size: " << myList.size() << endl;

    // Adding another booking, which overlaps with 3 existing overlapping bookings.
    cout << "\n>>> Adding another booking, which overlaps with 3 existing overlapping bookings:" << endl;
    bookingPtr = myList.addBooking(g4, QDate(2018,3,2), QDate(2018,3,15), &g4);
    if (bookingPtr == NULL)
        cout << "No vacant rooms available for those dates." << endl;

    // Output list size.
    cout << "\nCurrent list size: " << myList.size() << endl;

    // Output the list contents.
    cout << "\n>>> Outputting list contents:" << endl;
    for (int i = 0; i < myList.size(); i++)
        cout << myList[i]->toString() << endl << endl;

    // Delete the list and its objects.
    cout << ">>> Deleting the list contents and its objects." << endl;
    myList.deleteAll();

    // Output list size.
    cout << "\nCurrent list size: " << myList.size() << endl << endl;

    return EXIT_SUCCESS;
}
