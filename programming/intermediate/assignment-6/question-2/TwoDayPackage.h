// Interface file for derived class "TwoDayPackage" that inherits from
// "Package" base class
#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"
using namespace std;

class TwoDayPackage : public Package
{
public:
    TwoDayPackage(double the_cost, double the_weight, const string &the_sender, const string &the_recipient);

private:
    double extra_fee;
};

#endif
