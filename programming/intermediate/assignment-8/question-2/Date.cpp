// Implementation file for class 'Date' in Date.h header file.
// Contains the definitions for the constructors and overloaded outstream function.
#include "Date.h"

// Default constructor.
Date::Date()
{
    //
}

// Overloaded constructor that initialises an object with provided values for date/month/year.
Date::Date(int y, int m, int d) : year(y), month(m), day(d)
{
    //
}

// Overloaded outstream operator to output objects of type Date in dd/mm/yyyy format.
ostream& operator << (ostream& cout, const Date& d)
{
    // Output an extra zero if the day is less than 10.
    if (d.day < 10)
        cout << "0" << d.day << "/";
    else
        cout << d.day << "/";

    // Output an extra zero if the month is less than 10.
    if (d.month < 10)
        cout << "0" << d.month << "/";
    else
        cout << d.month << "/";

    cout << d.year;
    return cout;
}
