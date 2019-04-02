// Interface file for class 'Publication' that represents publisher/date/
// title values. It uses the 'Date' class to accept a Date object. The
// constructor accepts the publisher and title as strings and the date as
// an object of type Date. There are also 3 accessor functions to get the
// values of the above.
#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <iostream>
using namespace std;

class Publication
{
public:
    // Default constructor
    Publication();

    // Constructor that accepts publisher/date/title
    Publication(const string& p, const Date& d, const string& t);

    // Accessor functions for the private members
    Date GetDate() const;
    string GetPublisher() const;
    string GetTitle() const;

private:
    string publisher;
    Date date;
    string title;
};

#endif // PUBLICATION_H
