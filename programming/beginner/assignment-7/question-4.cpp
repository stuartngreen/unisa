// Total number of hours worked by employees
#include <iostream>
using namespace std;

// Input the hours worked for each employee
void inputHours(float hoursP[], int n)
{
    for (int count = 0; count < n; count++)
    {
        cout << "Enter the hours worked by employee " << (count + 1) << ": ";
        cin >> hoursP[count];
    }
}

// Calculate the total hours worked by all employees
void calculateTotalHours(const float hoursP[], int n, float& totalhoursP)
{
    for (int count = 0; count < n; count++)
        totalhoursP += hoursP[count];
}

int main()
{
    const int NUM_EMPLOYEES = 6;
    float hours[NUM_EMPLOYEES];
    float totalhours = 0;

    inputHours(hours, NUM_EMPLOYEES);
    calculateTotalHours(hours, NUM_EMPLOYEES, totalhours);

    cout << "\nThe " << NUM_EMPLOYEES << " employees worked " << totalhours << " hours in total" << endl;

    return 0;
}
