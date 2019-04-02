// Calculate weekly pay of employees.
#include <iostream>
using namespace std;

// Calculate weekly pay of salaried employees.
float calcWeeklyPay(float annualSalaryP)
{
    float weeklyPay = annualSalaryP / 52;
    return weeklyPay;
}

// Calculate weekly pay of hourly paid employees.
float calcWeeklyPay(float hourlyRateP, int hoursWorkedP)
{
    float weeklyPay = hourlyRateP * hoursWorkedP;
    return weeklyPay;
}

int main ()
{
    float annualSalary, hourlyRate, weeklyPay;
    int hoursWorked;
    char yesOrNo = 'Y';
    bool salariedEmployee;

    // Output welcome message
    cout << "*************************************" << endl;
    cout << "* Welcome to Weekly Pay Calculator. *" << endl;
    cout << "*************************************" << endl;

    while (toupper(yesOrNo) == 'Y')
    {
        // Find out the employee type.
        do
        {
            cout << "\nIs the employee a salaried employee? (y/n): ";
            cin >> yesOrNo;
        }
        while (toupper(yesOrNo) != 'Y' && toupper(yesOrNo) != 'N');

        // Set boolean based on previous input.
        if (toupper(yesOrNo) == 'Y')
            salariedEmployee = true;
        else
            salariedEmployee = false;

        // Call functions to calculate the weekly pay based on boolean.
        if (salariedEmployee)
        {
            cout << "Enter the annual salary: R";
            cin >> annualSalary;
            weeklyPay = calcWeeklyPay(annualSalary);
        }
        else
        {
            cout << "Enter the hourly rate, followed by the hours worked: R";
            cin >> hourlyRate >> hoursWorked;
            weeklyPay = calcWeeklyPay(hourlyRate, hoursWorked);
        }

        // Display the weekly pay to 2 decimal points.
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "The employee's pay this week is R" << weeklyPay << endl;

        // Ask the user if they want to continue calculating.
        do
        {
            cout << "\nCalculate again? (y/n): ";
            cin >> yesOrNo;
        }
        while (toupper(yesOrNo) != 'Y' && toupper(yesOrNo) != 'N');
    }

    // End the program.
    cout << "\nThanks for using this program." << endl;
    return 0;
}
