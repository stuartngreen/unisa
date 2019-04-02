// Calculate and print pay slips
#include <iostream>
using namespace std;

void getData(string & theEmployeeP, float & theHoursWorkedP, float & thePayRateP)
{
    string theEmployeeName, theEmployeeSurname;

    // Capture the data
    cout << "Enter the employee's name and surname, the hours worked, and the pay rate: " << endl;
    cin >> theEmployeeName >> theEmployeeSurname >> theHoursWorkedP >> thePayRateP;

    // Concatenate the employee name
    theEmployeeP = theEmployeeName + " " + theEmployeeSurname;
}

// Calculate the employee's pay
float calculatePay(float theHoursWorkedP, float thePayRateP)
{
    const float HOURS_MAX = 40;
    float overtimePay = 0;

    // Check if there is overtime and calculate
    if (theHoursWorkedP > HOURS_MAX)
    {
        overtimePay = ((1.5 * thePayRateP) * (theHoursWorkedP - HOURS_MAX));
        return (thePayRateP * 40 + overtimePay);
    }
    else
    {
        return (thePayRateP * theHoursWorkedP);
    }
}

void printPaySlip(string theEmployeeP, float theHoursWorkedP, float thePayRateP, float thePayP)
{
    // Calculate overtime hours
    const float HOURS_MAX = 40;
    float overtimeHours = 0;
    if (theHoursWorkedP > HOURS_MAX)
        overtimeHours = theHoursWorkedP - HOURS_MAX;

    // Display pay slip
    cout << "\n======================================" << endl;
    cout << "Pay slip for " << theEmployeeP << endl;
    cout << "Hours worked: " << theHoursWorkedP << " hours" << endl;
    cout << "Overtime hours: " << overtimeHours << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Hourly pay rate: R " << thePayRateP << endl;
    cout << "Pay: R " << thePayP << endl;
    cout << "======================================\n" << endl;
    cout.precision(0);
}

int main()
{
    string theEmployee;
    float theHoursWorked;
    float thePayRate;
    float thePay;

    for (int i = 0; i < 5; i++)
    {
        getData(theEmployee, theHoursWorked, thePayRate);
        thePay = calculatePay(theHoursWorked, thePayRate);
        printPaySlip(theEmployee, theHoursWorked, thePayRate, thePay);
    }

    return 0;
}
