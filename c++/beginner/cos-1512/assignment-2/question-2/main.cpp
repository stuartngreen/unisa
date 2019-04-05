// Program to encode a text file.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void encodeText(ifstream& fileInput, ofstream& fileOutput)
{
    char next;
    while(fileInput.get(next))
    {
        // Replace certain letters with code values.
        switch (toupper(next))
        {
            case 'T':
                fileOutput << "1Y";
                break;
            case 'H':
                fileOutput << "1O";
                break;
            case 'J':
                fileOutput << "1X";
                break;
            case 'D':
                fileOutput << "1B";
                break;
            case 'A':
                fileOutput << "1S";
                break;
            case 'P':
                fileOutput << "1M";
                break;
            case 'I':
                fileOutput << "1Q";
                break;
            default:
                fileOutput.put(next);
        }
    }
}

int main ()
{
    ifstream fileInput;
    ofstream fileOutput;

    fileInput.open("letter.txt");
    if (fileInput.fail())
    {
        cout << "Failed to open input file." << endl;
        exit(1);
    }

    fileOutput.open("encode.txt");
    if (fileOutput.fail())
    {
        cout << "Failed to open output file." << endl;
        exit(1);
    }

    // Call encoder function.
    cout << "Encoding file..." << endl;
    encodeText(fileInput, fileOutput);
    cout << "Complete." << endl;

    fileInput.close();
    fileOutput.close();

    return 0;
}
