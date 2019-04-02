//Calculate employee's annual pay
#include <iostream>
using namespace std;

int main()
{
    float payAmount = 1700.00, annualPay;
    int payPeriods = 26;

    //Calculate annualPay
    annualPay = payAmount * payPeriods;

    //Display annual pay to decimal 2 digits
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The employee's annual pay is R" << annualPay << "." << endl;

    return 0;
}
