#include <iostream>
using namespace std;

int main()
{
    int age, finalMark;

    cout << "Enter age: ";
    cin >> age;
    cout << "Enter final mark for exam: ";
    cin >> finalMark;

    while (age < 30 && finalMark > 65)
    {
        cout << "This student qualifies for the internship." << endl;

        cout << "Enter age: ";
        cin >> age;
        cout << "Enter final mark for exam: ";
        cin >> finalMark;
    }

    return 0;
}
