// Implementation file for class 'Publication' in Publication.h header file.
// Contains the definitions for the constructors and overloaded outstream function.
#include "Date.h"
#include "Publication.h"

// Default constructor.
Publication::Publication()
{
    //
}

// Constructor that initialises an object with provided values for publisher/date/title.
Publication::Publication(const string& p, const Date& d, const string& t)
    : publisher(p), date(d), title(t)
{
    //
}

// Accessor to get date object values.
Date Publication::GetDate() const
{
    return date;
}

// Accessor to get publisher value.
string Publication::GetPublisher() const
{
    return publisher;
}

// Accessor to get title value.
string Publication::GetTitle() const
{
    return title;
}
