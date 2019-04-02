// Program to demonstrate the use of a function template. The function accepts
// arrays of any type and searches for a provided search term in the array. If
// found it returns the index value in the array, if not it returns -1.
#include<iostream>
#include<string>
using namespace std;

// Prototype for search function template, see bottom of file.
template<typename T>
int returnIndex(T theArray[], int theArraySize, T theSearchTerm);

// Prototype for output function template, see bottom of file.
template<typename T>
void output(int theReturnValue, T theSearchTerm);

int main ()
{
    const int ARRAY_SIZE = 10;
    int returnValue;

    // Declare arrays of different types.
    int     intArray[ARRAY_SIZE]      =   {1, 2, 3, 4, 5, 6};
    double  doubleArray[ARRAY_SIZE]   =   {1.4, 2.5, 3.6, 4.7, 5.8, 6.9};
    string  stringArray[ARRAY_SIZE]   =   {"dog", "cat", "fish", "lizard", "mouse"};
    char    charArray[ARRAY_SIZE]     =   {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    // Declare variables of different types for the search term.
    int     intTerm;
    double  doubleTerm;
    string  stringTerm;
    char    charTerm;

    // The next four groups of code ask for a value of a certain type,
    // call the search function template and assign the returned value to
    // a variable, then call the output message function.

    // For type int.
    cout << "\nEnter a search term of type int: ";
    cin >> intTerm;
    returnValue = returnIndex(intArray, ARRAY_SIZE, intTerm);
    output(returnValue, intTerm);

    // For type double.
    cout << "\nEnter a search term of type double: ";
    cin >> doubleTerm;
    returnValue = returnIndex(doubleArray, ARRAY_SIZE, doubleTerm);
    output(returnValue, doubleTerm);

    // For type string.
    cout << "\nEnter a search term of type string: ";
    cin >> stringTerm;
    returnValue = returnIndex(stringArray, ARRAY_SIZE, string(stringTerm));
    output(returnValue, stringTerm);

    // For type char.
    cout << "\nEnter a search term of type char: ";
    cin >> charTerm;
    returnValue = returnIndex(charArray, ARRAY_SIZE, charTerm);
    output(returnValue, charTerm);

    return 0;
}

// Function template that accepts an array of various type and searches for
// a provided value and returns the index if found.
template<typename T>
int returnIndex(T theArray[], int theArraySize, T theSearchTerm)
{
    for(int i = 0; i < theArraySize; i++)
    {
        if(theArray[i] == theSearchTerm)
            return i;
    }

    return -1;
}

// Function template to output a message based on returned value of the
// search function template.
template<typename T>
void output(int theReturnValue, T theSearchTerm)
{
    if (theReturnValue != -1)
        cout << "Search term \"" << theSearchTerm << "\" found at index " << theReturnValue << "." << endl;
    else
        cout << "Search term not found." << endl;
}
