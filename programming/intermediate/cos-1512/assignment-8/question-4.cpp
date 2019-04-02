// Program with a function template that searches arrays for a value.
#include<iostream>
#include<string>
using namespace std;

template<typename T>
void searchArray(T theArray[], int theArraySize, T theSearchTerm);

int main ()
{
    const int ARRAY_SIZE = 10;

    // Declare arrays of different types.
    int     intArray[ARRAY_SIZE]      =   {1, 2, 2, 3, 4, 5, 6};
    double  doubleArray[ARRAY_SIZE]   =   {1.4, 2.5, 3.6, 4.7, 5.8, 6.9};
    string  stringArray[ARRAY_SIZE]   =   {"dog", "cat", "fish", "fish", "fish", "lizard", "mouse"};
    char    charArray[ARRAY_SIZE]     =   {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    // Declare variables of different types for the search term.
    int     intTerm;
    double  doubleTerm;
    string  stringTerm;
    char    charTerm;

    // The next four groups of code ask for a value of a certain type and
    // call the search function template.

    // For type int.
    cout << "\nEnter a search term of type int: ";
    cin >> intTerm;
    searchArray(intArray, ARRAY_SIZE, intTerm);

    // For type double.
    cout << "\nEnter a search term of type double: ";
    cin >> doubleTerm;
    searchArray(doubleArray, ARRAY_SIZE, doubleTerm);

    // For type string.
    cout << "\nEnter a search term of type string: ";
    cin >> stringTerm;
    searchArray(stringArray, ARRAY_SIZE, string(stringTerm));

    // For type char.
    cout << "\nEnter a search term of type char: ";
    cin >> charTerm;
    searchArray(charArray, ARRAY_SIZE, charTerm);

    return 0;
}

// Function template that accepts an array of various type and searches
// for a provided value.
template<typename T>
void searchArray(T theArray[], int theArraySize, T theSearchTerm)
{
    bool searchTermFound = false;
    int count = 0;

    for(int i = 0; i < theArraySize; i++)
    {
        if(theArray[i] == theSearchTerm)
        {
            searchTermFound = true;  // Set to true if search term found.
            count++;  // Increment counter for amount of times found.
        }
    }

    // Output a message.
    if (searchTermFound)
    {
        if (count == 1)
            cout << "Search term \"" << theSearchTerm << "\" found " << "once." << endl;
        else if (count == 2)
            cout << "Search term \"" << theSearchTerm << "\" found " << "twice." << endl;
        else
            cout << "Search term \"" << theSearchTerm << "\" found " << count << " times." << endl;
    }
    else
        cout << "Search term \"" << theSearchTerm << "\" not found." << endl;
}
