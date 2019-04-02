// Program to convert names into the pig-latin version.
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char convertToLower(char *cstr);
char convertToPigLatin(char *cstr);
char convertFirstCharToUpper(char *cstr);
void output(char *cstr);

int main ()
{
    char first[21], last[41], fullname[61];

    cout << "\n--------------------------------" << endl;
    cout << ">   PIG-LATIN NAME CONVERTER   <" << endl;
    cout << "--------------------------------\n" << endl;

    // Get the first and last names from the user and input to c-strings.
    cout << "Please enter your first name (20 characters max):\n> ";
    cin.getline(first, 21);

    cout << "\nPlease enter your last name (40 characters max):\n> ";
    cin.getline(last, 41);

    // Convert first and last names all to lowercase.
    convertToLower(first);
    convertToLower(last);

    // Convert first and last names to pig-latin.
    convertToPigLatin(first);
    convertToPigLatin(last);

    // Convert first character of first and last names to uppercase.
    convertFirstCharToUpper(first);
    convertFirstCharToUpper(last);

    // Create new c-string for the full name.
    strcpy(fullname, first);
    strcat(fullname, " ");
    strcat(fullname, last);

    // Output the pig-latin version of the full name.
    output(fullname);

    return 0;
}

char convertToLower(char *cstr)
{
    // Loop through characters and convert to lowercase.
    for (int i = 0; i < strlen(cstr); i++)
        cstr[i] = tolower(cstr[i]);
    return *cstr;
}

char convertToPigLatin(char *cstr)
{
    // Check the first character...
    switch(toupper(cstr[0]))
    {
        // When the first character is a vowel...
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            strcat(cstr, "way"); // Append "way".
            break;

        // When the first character is a consonant...
        default:
            // Store the original first character.
            char firstChar[2] = { cstr[0] };

            // Move characters forward by one position.
            for (int i = 0; i < strlen(cstr); i++)
                cstr[i] = cstr[i + 1];

            strcat(cstr, firstChar); // Append original first character to end.
            strcat(cstr, "ay"); // Append "ay".
    }
    return *cstr;
}

char convertFirstCharToUpper(char *cstr)
{
    // Convert first character to uppercase.
    cstr[0] = toupper(cstr[0]);
    return *cstr;
}

void output(char *cstr)
{
    // Output the pig-latin version of the full name.
    cout << "\n--------------------------------" << endl;
    cout << "  Your pig-latin name is:" << endl;
    cout << "  " << cstr << endl;
    cout << "--------------------------------\n" << endl;
}
