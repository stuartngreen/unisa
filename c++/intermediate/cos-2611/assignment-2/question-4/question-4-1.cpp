//Test program for new function moveNthFront(int n).
#include <iostream>
#include "queueADT.h"
#include "queueAsArray.h"
using namespace std;

int main()
{
    int n;

    //Create a new queue for 6 elements.
    queueType<int> myQueue(6);

    //Populate queue with values from exercise 4 in Malik.
    myQueue.addQueue(5);
    myQueue.addQueue(11);
    myQueue.addQueue(34);
    myQueue.addQueue(67);
    myQueue.addQueue(43);
    myQueue.addQueue(55);

    //Output the original queue.
    cout << "The queue is: " << endl;
    cout << "5 11 34 67 43 55" << endl;

    cout << "\nWhich element should be moved to the front? ";
    cin >> n;

    myQueue.moveNthFront(n); //Call function to move selected element to front.

    //Output the new queue order.
    cout << "Processing queue:" << endl;
    while (!myQueue.isEmptyQueue())
    {
        cout << myQueue.front() << " ";
        myQueue.deleteQueue();
    }
    cout << endl;

    return 0;
}
