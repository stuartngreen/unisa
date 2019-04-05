// Implementation file for derived class 'Magazine' in Magazine.h header file (derived
// from 'Publication' class). Contains the definitions for the constructors and accessor
// function, as well as the overloaded << operator function.
#include "Date.h"
#include "Publication.h"
#include "Magazine.h"

// Default constructor
Magazine::Magazine()
{
    //
}

// Constructor that accepts publisher/date/title/issues per year
Magazine::Magazine(const string& p, const Date& d, const string& t, const int& ipy)
    : Publication(p, d, t), issuesPerYear(ipy)
{
    //
}

// Accessor to get issues per year value.
int Magazine::GetIssuesPerYear() const
{
    return issuesPerYear;
}

// Friend function to overload << operator to output Magazine objects
ostream& operator << (ostream& out, const Magazine& M)
{
    out << M.GetTitle() << endl;
    out << M.GetPublisher() << endl;
    out << M.GetDate() << endl;
    out << M.issuesPerYear << endl;
    return out;
}
