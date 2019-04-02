//
#include <iostream>
using namespace std;

// Function to show program description
void printDescription()
{
    cout << "\n****************************************************" << endl;
    cout << "This program inputs two numbers (pay rate and hours)" << endl;
    cout << "and outputs net pay." << endl;
    cout << "****************************************************\n" << endl;
}

// Function to calculate net pay
float computePaycheck(float payRateP, int hoursP)
{
    float netPay;
    const float TAX_RATE = 0.15;

    // Calculate net pay
    netPay = ((payRateP * hoursP) - (payRateP * hoursP * TAX_RATE));

    // Display net pay
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "\nThe net pay is R " << netPay << "." << endl;
}

int main()
{
    float payRate;
    int hours;

    cout << "Welcome to the Pay Roll." << endl;

    // Show program description
    printDescription();

    // Capture payRate and hours
    cout << "Please input the pay per hour:" << endl << "R ";
    cin >> payRate;
    cout << "\nPlease input the number of hours worked:" << endl;
    cin >> hours;

    // Call function to calculate and display net pay
    computePaycheck(payRate, hours);

    cout << "We hope you enjoyed this program." << endl;

    return 0;
}
