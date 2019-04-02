#include <iostream>
using namespace std;
int main()
{
    const int NUM_EMPLOYEES = 6;
    float hours[NUM_EMPLOYEES];
    int count;
    float totalhours;
    for (count = 0; count < NUM_EMPLOYEES; count++)
    {
        cout << "Enter the hours worked by employee " << (count + 1) << ": ";
        cin >> hours[count];
    }
    totalhours = 0;
    for (count = 0; count < NUM_EMPLOYEES; count++)
    {
        totalhours += hours[count];
    }
    cout << endl;
    cout << "The " << NUM_EMPLOYEES << " employees worked " << totalhours << " hours in total" << endl;
    return 0;
}
