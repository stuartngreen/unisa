// Interface and implementation for class 'Matrix'. An object of type Matrix
// represents an array of rows and columns with values. The class has a
// constructor which accepts integer values for amount of rows and cols and
// accessors to get the number of rows and number of cols, as well as a value
// in a particular row and column of the vector array. There is also a mutator
// to set the value of a particular row and column in the array, as well as
// an output function to display the values in the array.
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

template<class Object>
class Matrix
{
public:
    Matrix(int row = 0, int col = 0);
    void SetValue(Object value, int r, int c);
    Object GetValue(int r, int c) const;
    int GetRow() const;
    int GetCol() const;
    void OutPut(ostream& out) const;
private:
    vector< vector<Object> > array;
    int rows;
    int cols;
};

// Constructor that creates a vector array with provided dimensions.
template <class Object>
Matrix<Object>::Matrix(int row, int col)
{
    rows = row;
    cols = col;
    array.resize(row);
    for (int r = 0; r < row; r++)
        array[r].resize(col);
}

// SetValue assigns row r and column c of the Matrix to value
template <class Object>
void Matrix<Object>::SetValue(Object value, int r, int c)
{
    array[r][c] = value;
}

// GetValue returns the value in row r and col c of the Matrix
template <class Object>
Object Matrix<Object>::GetValue(int r, int c) const
{
    return array[r][c];
}

// GetRow returns rows
template<class Object>
int Matrix<Object>::GetRow() const
{
    return rows;
}

// GetCol returns cols
template<class Object>
int Matrix<Object>::GetCol() const
{
    return cols;
}

// Outputs the matrix in a tabular format
template <class Object>
void Matrix<Object>::OutPut(ostream& out) const
{
    int r, c;
    r = GetRow();
    c = GetCol();

    for (int i = 0; i < r; i++ )
    {
        for (int j = 0; j < c; j++)
            out << GetValue(i, j) << "\t";
        out << endl;
    }
}

// Operator+ is overloaded as a non-friend, non-member function. This
// function adds two Matrices
template<class Object>
Matrix<Object> operator+ (const Matrix<Object>& x, const Matrix<Object>& y)
{
    int xRow, xCol, yRow, yCol, sum;
    xRow = x.GetRow();
    xCol = x.GetCol();
    yRow = y.GetRow();
    yCol = y.GetCol();

    // Check that the matrices dimensions are the same.
    if (xRow != yRow || xCol != yCol)
    {
        cout << "You can only add matrices with the same dimensions." << endl;
        return 0;
    }
    else
    {
        Matrix<Object> z(xRow, xCol);

        // Add the corresponding values in matrices x and y and assign to z.
        for (int i = 0; i < xRow; i++ )
        {
            for (int j = 0; j < xCol; j++)
            {
                sum = x.GetValue(i, j) + y.GetValue(i, j);
                z.SetValue(sum, i, j);
            }
        }

        return z;
    }
}

#endif // MATRIX_H
