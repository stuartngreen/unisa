//variable diagrams revisited
#include <iostream>
using namespace std;
const int C = 200;
int func1(int n, int n1)
{
    n += 3;
    n1 -= n;
    return 2 + n + n1 * C;
}
void func2(int n, int & n1)
{
    n = C * n1;
    n1 = n - n1;
}
void func3(int & n, int & n1)
{
    int k;
    k = n1 + 3;
    n = k * 30;
    n1 = n + 2 * k;
}
int main()
{
    int n, m, j;
    n = 5;
    m = 10;
    j = func1(n, m);
    n = 15;
    m = 20;
    func2(n, m);
    n = 25;
    m = 30;
    func3(n, m);

    return 0;
}
