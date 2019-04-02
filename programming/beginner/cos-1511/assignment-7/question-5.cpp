#include <iostream>
using namespace std;
int main()
{
    int myArray[4][4], i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            myArray[i][j] = j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            cout << myArray[i][j] << "  ";
        cout << endl;
    }
    cout << i << " " << j;
    return 0;
}
