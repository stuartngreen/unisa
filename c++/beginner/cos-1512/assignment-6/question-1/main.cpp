// Assignment 6 -
// Program to determine total amount spent on phone calls to a particular number.
// User can enter a phone number which is then searched for in a .dat file containing call records.
// Phone number to test: 0337698210
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "PhoneCall.h"
using namespace std;

string captureNumber(string number);
void processFile(ifstream& inputFileP, PhoneCall call);

int main()
{
    // Output the program name heading.
    cout << "\n============================================================" << endl;
    cout << "                    PHONE RECORDS SEARCH                   " << endl;
    cout << "============================================================\n" << endl;

    // Capture the phone number to be searched.
    string phoneNumber = "";
    phoneNumber = captureNumber(phoneNumber);

    // Initialise theCall object to the provided number.
    PhoneCall theCall(phoneNumber);

    cout << "\n... Searching the records for the provided phone number ...\n" << endl;

    // Open the .dat file for processing.
    ifstream inputFile;
    inputFile.open("my-calls.txt");
    if (inputFile.fail())
    {
        cout << "Failed to open input file." << endl;
        exit(1);
    }

    // Process the file using the number provided.
    processFile(inputFile, theCall);

    return 0;
}

// Capture and validate the provided phone number.
string captureNumber(string number)
{
    cout << "Enter a phone number to search for (10 digits, no brackets or spaces):" << endl << "> ";
    cin >> number;

    // Check for correct length.
    while (number.length() != 10)
    {
        cout << "Oops, that's not right. Please enter a number of exactly 10 digits:" << endl;
        cin >> number;
    }

    return number;
}

// Process the file using the number provided.
void processFile(ifstream& inputFileP, PhoneCall call)
{
    float totalCharge = 0,
        longestCallCharge = 0;
    int noOfCalls = 0,
        longestCallLength = 0;

    while (!inputFileP.eof())
    {
        // Input the records in the file into a temporary PhoneCall object
        PhoneCall record;
        inputFileP >> record;

        // If the entered number and record's number match.
        if (call == record)
        {
            // Calculate the call charge and add to total, and count the call.
            totalCharge += record.calcCharge();
            noOfCalls++;

            // Find the longest call to the number and calculate the charge.
            if (record.getLength() > longestCallLength)
            {
                longestCallLength = record.getLength();
                longestCallCharge = record.calcCharge();
            }
        }
    }

    // Output the results found for the provided number.
    cout << "------------------------- RESULTS --------------------------\n" << endl;
    cout.setf(ios::fixed);
    cout.precision(2);

    if (noOfCalls > 0)
    {
        cout << "* There were " << noOfCalls << " calls made to " << call.getNumber();
        cout << " for a total of R" << totalCharge << "." << endl;
        cout << "* The longest call was " << longestCallLength;
        cout << " minutes which cost R" << longestCallCharge << "." << endl;
    }
    else
    {
        cout << "No calls were made to that number." << endl;
    }
    cout << "\n------------------------------------------------------------\n" << endl;
}
