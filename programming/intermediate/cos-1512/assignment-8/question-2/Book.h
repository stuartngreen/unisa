// Interface file for derived class 'Book' that inherits 'Publication'
// and adds two new private members, isbn and author. It has a default
// constructor, overloaded constructor (which accepts values for the
// inherited variables as well as the two new ones), and 2 accessor
// functions to get the isbn and author values. There is also an operator
// overload for << to output details of objects of type Book.
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book : public Publication
{
public:
    // Default constructor
    Book();

    // Constructor that accepts publisher/date/title/isbn/author
    Book(const string& p, const Date& d, const string& t, const string& i, const string& a);

    // Accessors for isbn and author
    string GetISBN() const;
    string GetAuthor() const;

    // Friend function to overload << operator to output Book objects
    friend ostream& operator << (ostream& out, const Book& B);

private:
    string isbn, author;
};

#endif // BOOK_H
