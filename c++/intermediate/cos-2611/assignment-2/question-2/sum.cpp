//Program to find and return the sum of an int array recursively.
#include <iostream>
using namespace std;

//Function header for sumArray. It takes 3 arguments:
//starting value for sum, array size (used for position), and the array to sum.
int sumArray(int sum, int pos, const int array[]);

int main()
{
    int sum;
    int array[10] = {5, 6, 10, 23, 6, 80, 7, 34, 16, 13 }; //10 integer array, sum = 200

    cout << "The sum of the integer array elements is: " << endl;
    sum = sumArray(0, 10, array); //Call the recursive function, starting with value 0 for sum in a 10 element array.
    cout << sum << endl;

    return 0;
}

int sumArray(int sum, int pos, const int array[])
{
    if (pos <= 0) //Base case: when pos = 0, all array elements have been processed.
        return sum; //Return total sum.

    pos--; //Start by reducing array size by 1 to get correct position value, and decrease on each recursive call.
    sum += array[pos]; //Add the value in the current pos to the sum.
    return sumArray(sum, pos, array); //Call itself recursively, each time the position will get closer to 0.
}
