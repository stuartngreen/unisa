#include <iostream>
using namespace std;
const float WEEKLYHOURS = 40.0;
int main()
{
    float wages, rate, hours;
    cout << "Enter hours worked and the rate paid per hour: ";
    cin >> hours >> rate;
    if (hours > WEEKLYHOURS)
        wages = WEEKLYHOURS * rate + 1.5 * rate * (hours - WEEKLYHOURS);
    else
        wages = hours * rate;
    cout << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The wages are R" << wages << endl;
    return 0;
}
