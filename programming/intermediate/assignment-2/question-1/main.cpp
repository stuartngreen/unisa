// Program to find and display outstanding fines for a vehicle registration
// number in a file, and to ouput the remaining records to a new file.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

void processFile(ifstream& fileInputP, ofstream& fileOutputP, string regNumberP)
{
    string fileRecord;
    float finesTotal = 0;

    cout << "Fines:" << endl;

    // Read the file data into a vector array.
    while (getline(fileInputP, fileRecord))
    {
        vector<string> fileData;
        int i = 0;

        // Insert a record into the vector array.
        fileData.push_back(fileRecord);

        // Search inserted record for registration number.
        // If a match is found...
        if (fileData[i].find(regNumberP) != string::npos)
        {
            // Create a separate string of the fine value and convert to float.
            int pos = fileData[i].find(" ");
            string fineText = fileData[i].substr(pos + 1);
            float fineValue = atof(fineText.c_str());

            // Keep track of total value.
            finesTotal += fineValue;

            // Output the fine value to the screen.
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "R" << fineValue << endl;
        }
        // ...else if no match is found output the record to the file.
        else
        {
            fileOutputP << fileRecord + "\n";
        }
        i++;
    }

    cout << "Total fine due R" << finesTotal;
}

int main ()
{
    ifstream fileInput;
    ofstream fileOutput;
    string regNumber;

    // Open the required files.
    fileInput.open("fines.txt");
    if (fileInput.fail())
    {
        cout << "Failed to open input file." << endl;
        exit(1);
    }

    fileOutput.open("outstanding-fines.txt");
    if (fileOutput.fail())
    {
        cout << "Failed to open output file." << endl;
        exit(1);
    }

    // Get the registration number.
    cout << "Please enter registration number: ";
    cin >> regNumber;

    processFile(fileInput, fileOutput, regNumber);

    fileInput.close();
    fileOutput.close();

    return 0;
}
