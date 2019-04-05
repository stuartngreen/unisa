#include <iostream>
#include <stack>
using namespace std;

bool isInLanguageLc(string w);

int main()
{
    string w;
    cout << "The language Lc is defined as Lc={a^nb^nc^(n+1)} where n >= 1." << endl;
    cout << "Enter a word to be tested (x to quit): " << endl;

    while (w != "x")
    {
        cin >> w;
        if (w == "x") break;

        if (isInLanguageLc(w)) //Pass the word to the function to test for validity.
            cout << "ACCEPT" << endl;
        else
            cout << "REJECT" << endl;
    }

    return 0;
}

//Function to test whether a provided word is in a language Lc.
//The language Lc is defined as Lc={a^nb^nc^(n+1)} where n >= 1.
bool isInLanguageLc(string w)
{
    stack<char> aStack;
    stack<char> bStack;

    int pos = 0;

    if (w[0] != 'a') //Reject the word if it does not begin with 'a'.
        return false;

    while(w[pos] == 'a') //While there are a's, push an x onto the A stack.
    {
        aStack.push('x');
        pos++; //Advance to next position in w.
    }

    if (w[pos] == 'b') //If there are b's...
    {
        while(w[pos] == 'b') //While there are b's, push an x onto the B stack.
        {
            bStack.push('x');
            pos++;
        }
    }

    if (w[pos] == 'c') //If there are c's...
    {
        aStack.push('x'); //Push an extra x to each stack to cater for the n+1 condition for c.
        bStack.push('x');

        while(w[pos] == 'c') //While there are c's, pop x's from both stacks, making sure they are not empty.
        {
            if (!aStack.empty() && !bStack.empty())
            {
                bStack.pop();
                aStack.pop();
                pos++;
            }
            else
                return false; //There are too many c's or the a's and b's didn't match up.
        }
    }

    return (aStack.empty() && bStack.empty()); //If the stacks are empty, accept the word.
}

