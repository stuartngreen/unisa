// Interface file for base class "Package" that represents package details:
// cost per kg, weight, sender and recipient.
// The following is available:
//  - Overloaded Constructor that accepts input values for the private and
//    protected member variables.
//  - Member function to calculate cost.
//  - Accessors to return the values of sender and recipient.
#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
using namespace std;

class Package
{
public:
    Package(double the_cost, double the_weight, const string& the_sender, const string& the_recipient);
    double calculate_cost() const;  // multiply weight by cost_per_kilogram
    string get_recipient() const;
    string get_sender() const;

protected:
    double cost_per_kilogram;
    double weight;

private:
    string sender;
    string recipient;
};

#endif
