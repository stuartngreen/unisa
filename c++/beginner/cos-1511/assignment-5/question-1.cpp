#include <iostream>
using namespace std;

int main()
{
    int counter = 3;
    int m = 5, n = 12;
    for (counter = 7; counter <= 16; counter++)
        switch (counter % 10)
        {
            case 0:
                cout << ", ";
                break;
            case 1:
                cout << "OFTEN ";
                break;
            case 2:
            case 8:
                cout << "IS ";
                break;
            case 3:
                cout << "NOT ";
                break;
            case 4:
            case 9:
                cout << "DONE ";
                break;
            case 5:
                cout << "WELL";
                break;
            case 6:
                cout << ".";
                break;
            case 7:
                cout << "WHAT ";
                break;
            default:
                cout << "Bad number.";
        }
    cout << endl;

    return 0;
}
