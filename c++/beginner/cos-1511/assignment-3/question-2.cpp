#include <iostream>
using namespace std;
int main()
{
    int total = 0,
        count = 0,
        number;
    cin >> number;
    do
    {
        total = total + number;
        count++;
        cin >> number; //input the number last so that it is checked immediately
    }
    while (number != -1);
    cout << "The number of data read is " << count << endl;
    cout << "The sum of the numbers entered is " << total << endl;
    return 0;
}
