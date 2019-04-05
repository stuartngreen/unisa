// More string manipulation
#include <iostream>
#include <string>
using namespace std;

// Double the string
string doubledString(string theStringP)
{
    return theStringP.append(theStringP);
}

// Expand the string by repeating middle two characters
string expandedString(string newStringP)
{
    int firstPosition = newStringP.size() / 2 - 1;
    int secondPosition = newStringP.size() / 2 + 1;

    newStringP.insert(firstPosition, newStringP.substr(firstPosition, 1));
    newStringP.insert(secondPosition, newStringP.substr(secondPosition, 1));

    return newStringP;
}

int main()
{
    string theString, newString;

    for (int i = 0; i < 6; i++)
    {
        // Prompt user to enter string
        cout << "Please enter a string: ";
        getline(cin, theString, '\n');

        // If number of characters is odd, double the string
        if (theString.size() % 2 == 1)
            newString = doubledString(theString);
        else
            newString = theString;

        newString = expandedString(newString);

        // Expand the string until it is greater than 40 chars
        while (newString.size() <= 40)
            newString = expandedString(newString);

        cout << "\n" << newString << "\n" << endl;
    }

    return 0;
}
