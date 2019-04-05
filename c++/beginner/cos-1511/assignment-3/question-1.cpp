#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Enter a value for 'a': ";
    cin >> a;
    if (a > 0)
        switch (a)
        {
        case 1:
            a = a + 3;
        case 3:
            a++;
            break;
        case 6:
            a = a + 6;
        case 8:
            a = a * 8;
            break;
        default:
            a--;
        }
    else
        a = a + 2;
    cout << "New value for 'a': " << a;
    return 0;
}
