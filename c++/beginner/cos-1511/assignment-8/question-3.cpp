// Erase every odd 't' and append 'h' to every even 't'.
#include <iostream>
#include <string>
using namespace std;

// Perform edits on user inputted string
string changedString(const string inputStringP)
{
    string editedString = inputStringP;
    int position = inputStringP.find('t');
    int counter = 0;

    while (position != -1)
    {
        // Increase counter for each occurrence of 't'
        counter++;

        if (counter % 2 != 0)   // Odd 't'
        {
            editedString.erase(position, 1);
        }
        else    // Even 't'
        {
            position++;
            editedString.insert(position, "h");
        }

        // Find the next 't'
        position = editedString.find('t', position);
    }

    return editedString;
}

int main()
{
    string inputString = "";

    // Prompt user to enter a sentence
    do
    {
        cout << "Please enter a sentence: ";
        getline(cin, inputString, '\n');

        // Call function to edit string and return result
        cout << changedString(inputString) << '\n' << endl;

    } while (inputString != "NOTHING MORE");

    return 0;
}
