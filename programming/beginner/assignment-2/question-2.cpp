#include <iostream>
using namespace std;
int main()
{
    int counter = 3;
    int m = 5, n = 12;
    while (n > m)
    {
        if (n - m > 1)
            counter ++;
        n -= 2;
    }
    cout << counter << " " << n << endl;
    return 0;
}
