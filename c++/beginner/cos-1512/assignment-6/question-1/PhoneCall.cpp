// Implementation file for class "PhoneCall" in PhoneCall.h header file.
// Contains all the definitions for the declared functions in the class.
#include "PhoneCall.h"

// Default constructor that initialises private member variable values.
PhoneCall::PhoneCall() : number(""), length(0), rate(0)
{
    // Intentionally empty.
}

// Overloaded constructor that accepts values for the 3 member variables.
PhoneCall::PhoneCall(string theNumber, int theLength, float theRate)
{
    number = theNumber;
    length = theLength;
    rate = theRate;
}

// Destructor
PhoneCall::~PhoneCall()
{
    // Intentionally empty.
}

// Accessor functions to return values of private member variables.
string PhoneCall::getNumber()
{
    return number;
}

int PhoneCall::getLength()
{
    return length;
}

float PhoneCall::getRate()
{
    return rate;
}

// Calculate the amount charged for the call.
float PhoneCall::calcCharge()
{
    return length * rate;
}

// Overload equality operator (==) to compare two phone calls.
bool operator == (const PhoneCall& call1, const PhoneCall& call2)
{
    if (call1.number == call2.number)
        return true;
}

// Overload stream extraction operator (>>) to input values of type 'PhoneCall'.
istream& operator >> (istream& ins, PhoneCall& call)
{
    ins >> call.number >> call.length >> call.rate;
}

// Overload stream insertion operator (<<) to output values of type 'PhoneCall'.
ostream& operator << (ostream& outs, PhoneCall& call)
{
    outs << call.number << "\t" << call.length << "\t" << call.rate << endl;
}
