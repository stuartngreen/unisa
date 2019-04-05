// Interface file for derived class 'Magazine' that inherits 'Publication'
// and adds one new private member, issues per year. It has a default
// constructor, overloaded constructor (which accepts values for the
// inherited variables as well as the new one), and an accessor function
// to get the issues per year value.  There is also an operator overload
// for << to output details of objects of type Magazine.
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <iostream>
using namespace std;

class Magazine : public Publication
{
public:
    // Default constructor
    Magazine();

    // Constructor that accepts publisher/date/title/issues per year
    Magazine(const string& p, const Date& d, const string& t, const int& ipy);

    // Accessor issues per year
    int GetIssuesPerYear() const;

    // Friend function to overload << operator to output Magazine objects
    friend ostream& operator << (ostream& out, const Magazine& M);

private:
    int issuesPerYear;
};

#endif // MAGAZINE_H
