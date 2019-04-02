// Interface file for class 'Date' that represents day/month/year values.
// There is a default constructor and overloaded constructor that accepts
// year, month and day values in that order. There is also an overloaded
// outstream operator to output objects of type 'Date'.
#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
public:
    // Default constructor
    Date();

    // Constructor that accepts y/m/d values.
    Date(int y, int m, int d);

    // Overloaded outstream operator to output objects of type Date.
    friend ostream& operator << (ostream& cout, const Date& d);

private:
    int year, month, day;
};

#endif // DATE_H
