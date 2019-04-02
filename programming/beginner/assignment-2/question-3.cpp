#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    bool found;
    cout << "Enter two integers: ";
    cin >> a >> b;
    if ((a > a * b) && (10 < b))    //1st if
        found = a > b;
    else                            //1st else
    {
        found = a < b;
        if (found)                  //2nd if
        {
            a = 3;
            c = 15;
        }
        if (b < a)                  //3rd if
        {
            b = 0;
            a = 1;
        }
    }
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "found: " << found << endl;
    return 0;
}
