// Implementation file for base class "Package" in Package.h header file.
// Contains all the definitions for the declared functions in the class.
#include "Package.h"

// Overloaded Constructor that accepts input values for the private and
// protected member variables.
Package::Package(double the_cost, double the_weight,
        const string& the_sender, const string& the_recipient)
{
    cost_per_kilogram = the_cost;
    weight = the_weight;
    sender = the_sender;
    recipient = the_recipient;
}

// Member function to calculate cost.
double Package::calculate_cost() const
{
    return weight * cost_per_kilogram;
}

// Accessor to return the value of recipient.
string Package::get_recipient() const
{
    return recipient;
}

// Accessor to return the value of sender.
string Package::get_sender() const
{
    return sender;
}
