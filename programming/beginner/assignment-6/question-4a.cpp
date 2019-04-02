// Calculate and display tax due
#include <iostream>
using namespace std;

// Function to calculate the tax due
float tax (float amountEarnedP, float taxRateP)
{
    return (amountEarnedP * taxRateP);
}

int main()
{
    float amountEarned, taxRate, amountDue;

    // Capture amount earned and tax rate
    cout << "Enter the amount earned: R ";
    cin >> amountEarned;
    cout << "Enter the tax rate: ";
    cin >> taxRate;

    // Call function tax() to calculate tax due
    amountDue = tax(amountEarned, taxRate);

    // Display output message
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "\nThe tax amount due is R " << amountDue << "." << endl;

    return 0;
}
