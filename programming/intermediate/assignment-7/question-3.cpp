// Program that uses a recursive function to sum numbers between two values (inclusive).
#include <iostream>
using namespace std;

double calcSum(int first, int last);

int main ()
{
    int firstNum, lastNum;

    // Get two integers from the user.
    cout << "\nThis program will calculate the sum of the integers between any two numbers (inclusive).\n" << endl;
    cout << "Please enter two numbers:\n> ";
    cin >> firstNum >> lastNum;

    // Call the recursive function to sum the numbers.
    cout << "\nThe answer is: " << calcSum(firstNum, lastNum) << endl;

    return 0;
}

// Recursive function to sum numbers between two values (inclusive).
double calcSum(int first, int last)
{
    if (first <= last)
        return first + calcSum(first + 1, last); // Call the function until first reaches last's value.
    else
        return 0;
}
