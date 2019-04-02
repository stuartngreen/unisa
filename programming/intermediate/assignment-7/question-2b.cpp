// Program to read a list of integers into a vector from either a file or keyboard input.
// It then outputs a sorted list (largest to smallest) of those integers, including the
// number of occurrences of each number.
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>  // for exit();
#include <string>
#include <sstream>
using namespace std;

// Function prototypes, see bottom of file for definitions.
vector<int> getNumbers();
vector<int> getNumbers(char const *filename);
vector< vector<int> > getValuesAndCounts(vector<int> theSuppliedList);
vector< vector<int> > sortList(vector< vector<int> > theList);
int findLargest(const vector<int> theList, int currentIndex);
void output(vector< vector<int> > theSortedList);

int main ()
{
    char userChoice;
    char filename[26];
    vector<int> listOfNumbers;
    vector< vector<int> > sortedList;

    // Output the program description.
    cout << "\n-----------------------------------------------------------" << endl;
    cout << " This program will examine a list of numbers, find" << endl;
    cout << " the distinct numbers, count their occurrences, and" << endl;
    cout << " then output a sorted list from largest to smallest." << endl;
    cout << "-----------------------------------------------------------" << endl;

    // Ask the user which input method to use for the list of numbers.
    cout << "\nWould you like to input values manually with the (k)eyboard, or from a (f)ile?\n> ";
    cin >> userChoice;
    userChoice = toupper(userChoice);

    // Keep asking until a valid choice is made.
    while ((userChoice != 'K') && (userChoice != 'F'))
    {
        cout << "\nPlease enter either 'k' for keyboard input or 'f' for file input:\n> ";
        cin >> userChoice;
        userChoice = toupper(userChoice);
    }
    cin.ignore(1, '\n'); // Get rid of newline character in stream.

    // Call different functions based on selected input type (keyboard or file).
    switch(userChoice)
    {
        // For keyboard user input.
        case 'K':
            listOfNumbers = getNumbers();
            break;

        // For file input.
        case 'F':
            // Get the filename to process from the user.
            cout << "\nPlease enter the name of the file (max 25 chars) to load data from:\n> ";
            cin >> filename;

            // Send the filename to the overloaded getNumbers function.
            listOfNumbers = getNumbers(filename);
            break;

        default:
            cout << "Something went wrong." << endl;
            exit(1);
    }

    // Get the list of distinct values and counts and sort the list.
    sortedList = getValuesAndCounts(listOfNumbers);

    // Output the sorted list.
    output(sortedList);

    return 0;
}

// Get the list of numbers manually (keyboard input) and insert into a vector.
vector<int> getNumbers()
{
    string numbers;
    int number;
    vector<int> v;

    // Get a line of numbers into a string.
    cout << "\nPlease enter a list of numbers (space separated):\n> ";
    getline(cin, numbers);

    // Send the numbers to a vector.
    stringstream stream(numbers);
    while (stream >> number)
        v.push_back(number);

    return v;
}

// Get the numbers from the specified filename and insert into a vector.
vector<int> getNumbers(char const *filename)
{
    ifstream inputFile;
    int number;
    vector<int> v;

    // Open the file for processing.
    cout << "\nProcessing filename \"" << filename << "\"..." << endl;
    inputFile.open(filename);
    if (inputFile.fail())
    {
        cout << "Failed to open input file." << endl;
        exit(1);
    }

    // Send the file contents to a vector.
    while (inputFile >> number)
        v.push_back(number);

    inputFile.close();

    return v;
}

// Get the list of distinct values and count occurrences of each.
vector< vector<int> > getValuesAndCounts(vector<int> theSuppliedList)
{
    int currentValueCount, currentValue;
    bool valueExists;
    vector<int> values, counts;
    vector< vector<int> > valuesAndCounts;

    // Start processing the supplied list of numbers.
    // After this loop is done we will have two vectors, one with the
    // distinct values, and one with the occurrences of those values.
    for (int i = 0; i < theSuppliedList.size(); i++)
    {
        currentValueCount = 0; // Reset the counter for each iteration.
        currentValue = theSuppliedList[i]; // Assign current indexes value.
        valueExists = false;

        // Check if the current value already exists in the values vector.
        for (int j = 0; j < values.size(); j++)
        {
            if (values[j] == currentValue)
                valueExists = true;
        }

        // If the value does not yet exist in the values vector it needs to be counted and inserted...
        if (!valueExists)
        {
            values.push_back(currentValue); // Append the value to the values vector...

            // Then check occurrences of that value appears in the supplied list of numbers...
            for (int k = 0; k < theSuppliedList.size(); k++)
            {
                if (theSuppliedList[k] == currentValue)
                    currentValueCount++;
            }
            counts.push_back(currentValueCount); // Append the value's occurrence count to the counts vector.
        }
    }

    // Insert the values and counts vectors into a 2D vector.
    valuesAndCounts.push_back(values);
    valuesAndCounts.push_back(counts);

    // Now sort by value, largest to smallest.
    valuesAndCounts = sortList(valuesAndCounts);

    return valuesAndCounts;
}

// Cycle through the values vector and sort by largest to smallest.
vector< vector<int> > sortList(vector< vector<int> > theList)
{
    int largest, swapMe;

    // Find the largest value's index, and swap its value with the current index.
    // So for each iteration, the next largest value will be placed in the next slot.
    for (int i = 0; i < theList[0].size(); i++)
    {
        // For each iteration find the largest value's index in the vector.
        largest = findLargest(theList[0], i);

        // Swap the current iteration indexes value with the largest value in the vector.
        // Also switch the corresponding occurence counts to keep them matched up.
        // theList[0][i] are the distinct values.
        // theList[1][i] are the occurrence counts.
        for (int j = 0; j < 2; j++)
        {
            swapMe = theList[j][i];
            theList[j][i] = theList[j][largest];
            theList[j][largest] = swapMe;
        }
    }
    return theList;
}

// Find the index of the largest value in a vector.
int findLargest(const vector<int> theList, int currentIndex)
{
    // Set 'largest' to the current index and value as a starting point.
    int largest = theList[currentIndex],
        largestIndex = currentIndex;

    // Check the values following on from the current index...
    for (int i = currentIndex + 1; i < theList.size(); i++)
    {
        // If the next value is larger...
        if (theList[i] > largest)
        {
            // Set largest to this index and value.
            largest = theList[i];
            largestIndex = i;
        }
    }
    return largestIndex;
}

// Output the sorted list.
void output(vector< vector<int> > theSortedList)
{
    cout << "\n-----------------" << endl;
    cout << "| No.\t| Count\t|" << endl;
    cout << "-----------------" << endl;

    // theSortedList[0][i] are the distinct values.
    // theSortedList[1][i] are the occurrence counts.
    for (int i = 0; i < theSortedList[0].size(); i++)
        cout << "| " << theSortedList[0][i] << "\t| " << theSortedList[1][i] << "\t|" << endl;

    cout << "-----------------" << endl;
}
