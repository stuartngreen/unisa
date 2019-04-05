//Program to test whether a provided word is in a language L.
//The language L is defined as L={a^nb^(n-1)} where n >= 1.
#include <iostream>
#include <stack>
#include "queueADT.h"
#include "queueAsArray.h"
using namespace std;

bool isInLanguageL(queueType<char> & w);

int main()
{
    string s;
    queueType<char> w;

    cout << "The language L is defined as L={a^nb^(n-1)} where n >= 1." << endl;
    cout << "Enter a word to be tested (x to quit): " << endl;

    while (s != "x")
    {
        cin >> s;
        if (s == "x") break;

        //Clear the queue.
        w.initializeQueue();

        //Add the entered word to the queue.
        for (int i = 0; i < s.length(); i++)
            w.addQueue(s[i]);

        //Pass the queue to the function to test for validity.
        if (isInLanguageL(w))
            cout << "ACCEPT" << endl;
        else
            cout << "REJECT" << endl;
    }

    return 0;
}

//Function to test whether a provided word is in the language L using a queue.
bool isInLanguageL(queueType<char> & w)
{
    stack<char> stack;

    //Reject the word if it does not begin with 'a'.
    if (w.front() != 'a')
        return false;

    //Count the consecutive a's in the queue while the queue is not empty by pushing to a stack.
    while (!w.isEmptyQueue() && w.front() == 'a')
    {
        stack.push('x');
        w.deleteQueue();
    }

    //If there is only one x on the stack and the queue is empty, accept 'a'.
    if (w.isEmptyQueue() && stack.size() == 1)
        return true;

    //Check for b's and count them by popping from the stack.
    if (!w.isEmptyQueue() && w.front() == 'b')
    {
        stack.pop(); //Reduce the stack by one to cater for n-1 condition.
        while (!w.isEmptyQueue() && w.front() == 'b')
        {
            stack.pop(); //Pop the stack x's while reading b's.
            w.deleteQueue();
        }
    }
    else
        return false;

    return (stack.size() == 0 && w.isEmptyQueue()); //Accept the word if the stack and the queue are empty.
}

