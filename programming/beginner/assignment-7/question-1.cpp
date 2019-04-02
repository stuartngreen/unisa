#include <iostream>
using namespace std;
int x;
void mickey(int& a, int b)
{
    int first;
    first = b + 12;
    a = 2 * b;
    b = first + 4;
}
void minnie(int u, int& v)
{
    int second;
    second = x;
    v = second + 4;
    x = u + v;
}
int main()
{
    int first;
    int second = 5;
    x = 6;
    mickey(first,second);
    cout << first << " " << second << " " << x << endl;
    minnie(first,second);
    cout << first << " " << second << " " << x << endl;
    return 0;
}
