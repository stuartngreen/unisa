// Sort function that accepts a vector of integers and orders them from smallest to largest.
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> theList);
int findSmallest(const vector<int> theList, int i);
void output(vector<int> sortedList);

int main( )
{
    vector<int> listOfNumbers;
    int number;

    // Ask for a list of numbers from the user.
    cout << "This program will sort a list of non-negative numbers from smallest to largest.\n" << endl;
    cout << "Enter a list of numbers (enter a negative number to end):\n> ";
    cin >> number;

    while (number > -1) // Keep inserting numbers into vector until a negative is input.
    {
        listOfNumbers.push_back(number);
        cin >> number;
    }

    // Call the sorting function.
    sort(listOfNumbers);

    return 0;
}

void sort(vector<int> theVector)
{
    int smallest, swapMe;

    // Find the smallest value's index, and swap its value with the current iteration.
    for (int i = 0; i < theVector.size(); i++)
    {
        // For each iteration find the smallest value's index in the vector.
        smallest = findSmallest(theVector, i);

        // Swap the current iteration indexes value with the smallest value in the vector.
        // i.e. move the smallest value to the current iteration's index.
        swapMe = theVector[i];
        theVector[i] = theVector[smallest];
        theVector[smallest] = swapMe;
    }

    // Call the output function.
    output(theVector);
}

int findSmallest(const vector<int> theVector, int currentIndex)
{
    // Set smallest to the current index and value as a starting point.
    int smallest = theVector[currentIndex], smallestIndex = currentIndex;

    // Check the values following on from the current index.
    for (int i = currentIndex + 1; i < theVector.size(); i++)
    {
        // If the next value is smaller...
        if (theVector[i] < smallest)
        {
            // Set smallest to this index and value.
            smallest = theVector[i];
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

void output(vector<int> sortedList)
{
    // Output the sorted values in an ordered list.
    cout << "\nThe sorted list (smallest to largest):" << endl;
    for (int i = 0; i < sortedList.size(); i++)
        cout << i + 1 << ". " << sortedList[i] << endl;
}
