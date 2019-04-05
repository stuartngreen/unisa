//Program to test whether a provided word is in a language L.
//The language L is defined as L={a^nb^(n-1)} where n >= 1.
#include <iostream>
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
    int count = 0;

    //Reject the word if it does not begin with 'a'.
    if (w.front() != 'a')
        return false;

    //Count the consecutive a's in the queue while the queue is not empty.
    while (!w.isEmptyQueue() && w.front() == 'a')
    {
        count++;
        w.deleteQueue();
    }

    //If there is only one 'a' and the queue is empty, accept.
    if (w.isEmptyQueue() && count == 1)
        return true;

    //Check for b's and count them.
    if (!w.isEmptyQueue() && w.front() == 'b')
    {
        count--; //Reduce the count by one to cater for n-1 condition.
        while (!w.isEmptyQueue() && w.front() == 'b')
        {
            count--; //Reduce the count total while reading b's.
            w.deleteQueue();
        }
    }
    else
        return false;

    return (count == 0 && w.isEmptyQueue()); //Accept the word if the count is zero and the queue is empty.
}

