#include <iostream>
using namespace std;

int main()
{
    // initialise the variables
    int next = 2, product = 1;

    // do the calculation
    while (next <= 5)
    {
        product = product * next;
        next++;
    }

    // output a message
    cout << "The product of 2 through 5 is " << product << endl;

    return 0;
}
