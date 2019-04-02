// Program to validate whether matriculants qualify for BSc in Computing.
#include <iostream>
#include <cassert>
using namespace std;

int main ()
{
    int marksMaths, marksScience, marksEnglish;
    char yesOrNo = 'Y';

    // Output welcome message.
    cout << "******************************************************" << endl;
    cout << "* Do you qualify to register for a BSc in Computing? *" << endl;
    cout << "******************************************************" << endl;

    while (toupper(yesOrNo) == 'Y')
    {
        // Input the matriculant's marks.
        cout << "\nPlease enter the marks obtained for Maths, Physical Science and English:" << endl;
        cin >> marksMaths >> marksScience >> marksEnglish;

        // Check that none are above 100%.
        assert(marksMaths <= 100 && marksScience <= 100 && marksEnglish <= 100);

        // Check that each mark is 60 or more, and output a message.
        if (marksMaths >= 60 && marksScience >= 60 && marksEnglish >= 60)
            cout << "Congratulations, you qualify for registration." << endl;
        else
            cout << "Unfortunately you fail to meet the qualification requirements." << endl;

        // Ask the user if they want to validate again.
        do
        {
            cout << "\nValidate another matriculant's marks? (y/n): ";
            cin >> yesOrNo;
        }
        while (toupper(yesOrNo) != 'Y' && toupper(yesOrNo) != 'N');
    }

    return 0;
}
