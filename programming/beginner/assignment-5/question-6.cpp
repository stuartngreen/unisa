#include <iostream>
using namespace std;

// Function to input two numbers
void inputNumbers(int & num1P, int & num2P)
{
    cout << "Please enter two integers: ";
    cin >> num1P >> num2P;
}

// Function to add two numbers
int fSum(int num1P, int num2P)
{
    return (num1P + num2P);
}

// Function to multiply two numbers
int fProduct(int num1P, int num2P)
{
    return (num1P * num2P);
}

// Function to display the output
void displayOutput(int num1P, int num2P, int sumP, int productP)
{
    cout << "The two integers are " << num1P << " and " << num2P << "." << endl;
    cout << "The sum of " << num1P << " and " << num2P << " is " << sumP;
    cout << " and the product is " << productP << "." << endl;
}

int main()
{
    int num1, num2, sum, product;

    // Input the numbers
    inputNumbers(num1, num2);

    // Add the numbers
    sum = fSum(num1, num2);

    // Multiply the numbers
    product = fProduct(num1, num2);

    // Display the output
    displayOutput(num1, num2, sum, product);

    return 0;
}
