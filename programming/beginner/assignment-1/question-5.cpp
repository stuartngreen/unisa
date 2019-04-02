//Calculate employee's annual pay
#include <iostream>
using namespace std;

int main()
{
    float payAmount, annualPay;
    int payPeriods;

    //Ask for payAmount and payPeriod values
    cout << "Please enter the employee's pay amount:" << endl;
    cin >> payAmount;
    cout << "Please enter the number of pay periods per year:" << endl;
    cin >> payPeriods;

    //Calculate annualPay
    annualPay = payAmount * payPeriods;

    //Display pay amount, pay periods and annual pay
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The pay amount is R" << payAmount << endl;
    cout << "There are " << payPeriods << " pay periods per year." << endl;
    cout << "The employee's annual pay is R" << annualPay << endl;

    return 0;
}
