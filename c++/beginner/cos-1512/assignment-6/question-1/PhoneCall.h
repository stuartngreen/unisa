#ifndef PHONECALL_H
#define PHONECALL_H

// Interface file for class "PhoneCall" that represents a phone number, call length, and call rate.
// The following is available:
//  - Default Constructor which initialises private member variables with default values.
//  - Overloaded Constructor that accepts input values for the private member variables.
//  - A Destructor.
//  - Accessors to return the values of private member variables.
//  - Friend function to calculate call charges.
//  - Friend functions to override ==, << and >> operators to enable use with values of type "PhoneCall".

#include <iostream>
using namespace std;

class PhoneCall
{
public:
    // Default constructor that initialises private member variable values.
    PhoneCall();

    // Overloaded constructor that accepts values for the 3 member variables.
    PhoneCall(string theNumber, int theLength = 0, float theRate = 0);

    // Destructor
    ~PhoneCall();

    // Accessor functions to return values of private member variables.
    string getNumber();
    int getLength();
    float getRate();

    // Calculate the amount charged for the call.
    float calcCharge();

    // Overload equality operator (==) to compare two phone calls.
    friend bool operator == (const PhoneCall& call1, const PhoneCall& call2);

    // Overload stream extraction operator (>>) to input values of type 'PhoneCall'.
    friend istream& operator >> (istream& ins, PhoneCall& call);

    // Overload stream insertion operator (<<) to output values of type 'PhoneCall'.
    friend ostream& operator << (ostream& outs, PhoneCall& call);

private:
    string number; // The phone number.
    int length;    // Length of call.
    float rate;    // Call rate per minute.
};

#endif
