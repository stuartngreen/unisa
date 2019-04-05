#include <iostream>
#include <stack>
using namespace std;

bool isInLanguageL2(string w);

int main()
{
    string w;
    cout << "The language L2 is defined as L={a^nb^(n-1)} where n >= 1." << endl;
    cout << "Enter a word to be tested (x to quit): " << endl;

    while (w != "x")
    {
        cin >> w;
        if (w == "x") break;

        if (isInLanguageL2(w)) //Pass the word to the function to test for validity.
            cout << "ACCEPT" << endl;
        else
            cout << "REJECT" << endl;
    }

    return 0;
}

//Function to test whether a provided word is in a language L2.
//The language L2 is defined as L={a^nb^(n-1)} where n >= 1.
bool isInLanguageL2(string w)
{
    stack<char> wStack;
    int pos = 0;

    if (w[0] != 'a') //Reject the word if it does not begin with 'a'.
        return false;

    while(w[pos]=='a')//While there are a's, push an x onto the stack.
    {
        wStack.push('x');
        pos++; //Advance to next position in w.
    }

    if (w.size() == 1 && wStack.size() == 1) //The word must be a single 'a', so accept.
        return true;

    if (w[pos] == 'b') //If there are b's...
    {
        wStack.pop(); //Pop once to cater for the n-1 condition for b.

        while (w[pos] == 'b') //While there are b's, pop an x from the stack, making sure the stack doesn't become empty.
        {
            if (!wStack.empty())
            {
                wStack.pop(); //Pop an x.
                pos++; //Advance to next position in w.
            }
            else
                return false; //There are too many b's.
        }
        return wStack.empty(); //If the stack is empty, accept the word.
    }
    return false; //Return false for any other case.
}

