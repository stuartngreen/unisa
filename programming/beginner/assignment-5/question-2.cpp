#include <iostream>
using namespace std;

int main()
{
    int i, j;

    for (i = 1; i <= 5; i++)
    {
        for (j = (i + 1); j <= 5; j++)
            cout << '\t' << j;
        cout << endl;
    }

    return 0;
}
