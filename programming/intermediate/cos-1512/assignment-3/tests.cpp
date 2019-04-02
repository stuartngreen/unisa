#include <iostream>
using namespace std;

int main ()
{
    /*
    int *p1, *p2, v1 = 1, v2 = 2;

    p1 = &v1;
    p2 = &v2;

    cout << "p1 = " << p1 << ", p2 = " << p2 << ", *p1 = " << *p1 << ", *p2 = " << *p2 << ", v1 = " << v1 << ", v2 = " << v2 << endl;

    //p1 = p2;
    *p1 = *p2;

    cout << "p1 = " << p1 << ", p2 = " << p2 << ", *p1 = " << *p1 << ", *p2 = " << *p2 << ", v1 = " << v1 << ", v2 = " << v2 << endl;
    */

    /*typedef int* int_ptr;
    int_ptr p1;
    p1 = new int;
    *p1 = 23;
    int a = 1;
    p1 = &a;
    delete p1;
    //cout << *p1;
    */

    /*typedef int* int_ptr;
    int_ptr p2;
    int nrElements;

    cout << "Enter the number of elements in the array: " << endl;
    cin >> nrElements;

    p2 = new int[nrElements];

    int a[500];

    for (int i = 0; i < nrElements; i++)
    {
        p2[i] = i;
        a[i] = p2[i];
        cout << a[i] << " ";
    }*/

    int value1 = 10;
    int value2 = 40;
    int *ptr1 = &value1;
    int *ptr2 = &value2;
    ptr1 = ptr2;
    cout << *ptr1 << endl;
    cout << *ptr2 << endl;

    return 0;
}
