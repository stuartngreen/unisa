// Program to demonstrate inheritance from 'Publication' class in derived classes 'Book'
// and 'Magazine'. Declares objects of type Book and Magazine and outputs the details.
#include <iostream>
#include "Date.h"
#include "Publication.h"
#include "Book.h"
#include "Magazine.h"
using namespace std;

int main()
{
    // Declare object B of type Book
    Book B("FisherKing", Date(2000, 1, 1), "Global Warming", "123456789", "Ann Miller");

    // Output details of Book object B
    cout << "--- Details of Book B ---" << endl;
    cout << B << endl;

    // Declare object M of type Magazine
    Magazine M("Blue Marlin", Date(2005, 2, 2), "The Earth and the Environment", 12);

    // Output details of Magazine object M
    cout << "--- Details of Magazine M ---" << endl;
    cout << M << endl;

    return 0;
}
