// Test program for additional operations added to the linkListType class,
// namely returnItem(int n) and deleteItem(int n).
// Uses D.S. Malik's linkListType and unorderedLinkedList classes.
#include <iostream>
#include <cctype>
#include "linkedList.h"
#include "unorderedLinkedList.h"
using namespace std;

int main()
{
    char c;
    int item;
    unorderedLinkedList<int> myList;


    //Insert some values into the list.
    myList.insertLast(12);
    myList.insertLast(26);
    myList.insertLast(15);
    myList.insertLast(5);
    myList.insertLast(44);
    myList.insertLast(3);
    myList.insertLast(67);
    myList.insertLast(99);
    myList.insertLast(4);
    myList.insertLast(21);


    //Output the size of the list and the list contents.
    cout << "The list has " << myList.length() << " items:" << endl;
    myList.print();
    cout << endl;


    //Begin testing the return function.
    cout << "\nTesting return function:" << endl;
    cout << "------------------------------" << endl;

    do
    {
        cout << "Enter the number of the item to return: ";
        cin >> item;
        cout << myList.returnItem(item); //Call return member function.
        cout << "\nReturn another item? (y/n): ";
        cin >> c;
        cout << endl;
    }
    while (toupper(c) != 'N' );


    //Begin testing the delete function.
    cout << "Testing delete function:" << endl;
    cout << "------------------------------" << endl;

    do
    {
        cout << "Enter the number of the item to delete: ";
        cin >> item;
        myList.deleteItem(item); //Call delete member function.
        cout << "The list has " << myList.length() << " items:" << endl;
        myList.print();
        cout << "\nDelete another item? (y/n): ";
        cin >> c;
        cout << endl;
    }
    while (toupper(c) != 'N' );

    return 0;
}
