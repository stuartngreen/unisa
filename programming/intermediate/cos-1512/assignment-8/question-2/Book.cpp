// Implementation file for derived class 'Book' in Book.h header file (derived from
// 'Publication' class). Contains the definitions for the constructors and accessor
// functions, as well as the overloaded << operator function.
#include "Date.h"
#include "Publication.h"
#include "Book.h"

// Default constructor
Book::Book()
{
    //
}

// Constructor that accepts publisher/date/title/isbn/author
Book::Book(const string& p, const Date& d, const string& t, const string& i, const string& a)
    : Publication(p, d, t), isbn(i), author(a)
{
    //
}

// Accessor to get ISBN value.
string Book::GetISBN() const
{
    return isbn;
}

// Accessor to get author value.
string Book::GetAuthor() const
{
    return author;
}

// Friend function to overload << operator to output Book objects
ostream& operator << (ostream& out, const Book& B)
{
    out << B.GetTitle() << endl;
    out << B.GetPublisher() << endl;
    out << B.GetDate() << endl;
    out << B.author << endl;
    out << B.isbn << endl;
    return out;
}
