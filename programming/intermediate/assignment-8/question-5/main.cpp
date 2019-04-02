// Program to test the class 'Matrix'. The tested operations are: declaring
// Matrix objects, filling them with values, adding matrices together and
// outputting the matrix values.
#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    // Declare three 2x2 integer Matrix objects.
    Matrix<int> M1(2, 2), M2(2, 2), M3(2, 2);

    // Set the values in Matrix object M1.
    M1.SetValue(1, 0, 0);
    M1.SetValue(2, 0, 1);
    M1.SetValue(3, 1, 0);
    M1.SetValue(4, 1, 1);

    // Set the values in Matrix object M2.
    M2.SetValue(5, 0, 0);
    M2.SetValue(6, 0, 1);
    M2.SetValue(7, 1, 0);
    M2.SetValue(8, 1, 1);

    // Add M1 and M2 together and assign to M3.
    M3 = M1 + M2;

    // Output the three matrices.
    cout << "\nM1:" << endl;
    M1.OutPut(cout);
    cout << "\nM2:" << endl;
    M2.OutPut(cout);
    cout << "\nM1 + M2:" << endl;
    M3.OutPut(cout);

    return 0;
}
