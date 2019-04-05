//Program to generate a pattern of stars in a triangle shape using a recursive function.
#include <iostream>
using namespace std;

void generatePattern();
void generatePattern(int current, int limit);

int main()
{
    int lines = 0;

    generatePattern(); //Generate pattern required by exercise question.

    //Request line amount from user.
    cout << "\nEnter amount of lines to generate for each half of the pattern: ";
    cin >> lines;
    cout << endl;

    generatePattern(0, lines); //Generate pattern based on user input.

    return 0;
}

void generatePattern()
{
    generatePattern(0, 4);
}

void generatePattern(int current, int limit)
{
    if (current == limit) //Base case: End when limit is reached.
        return;

    //Output first half of pattern, 1 more star per line each time the function is called.
    for (int i = 0; i <= current; i++)
        cout << "*";
    cout << endl;

    generatePattern(current + 1, limit); //Calls itself but one step closer to the limit.

    //Output second half of pattern, 1 less star per line each time the function is completing.
    for (int i = 0; i <= current; i++)
        cout << "*";
    cout << endl;
}
