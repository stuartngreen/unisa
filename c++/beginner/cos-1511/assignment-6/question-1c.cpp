#include <iostream>
using namespace std;

int main()
{
    int i = 1, n = 10;

    while (i <= n)
    {
        if (i < 5 && i != 2)
        {
            cout << 'X';
        }
        i++;
    }

    return 0;
}
