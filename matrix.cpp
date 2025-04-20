#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    Matrix(int row, int col)
    {
        m_row = row;
        m_col = col;
        // create the matrix
        matrix.resize(m_row, vector<int>(m_col));
    }
    void fillMatrix()
    {
        cout << "Enter elements of the matrix (" << m_row << "x" << m_col << "):\n";
        // traverse the matrix vector
        for (int i = 0; i < m_row; i++)
        {
            for (int j = 0; j < m_col; j++)
            {
                // input each value of the matrix
                cin >> matrix[i][j]; 
            } 
        }           
    }
    void printMatrix()
    {
        cout << "printing Matrix: " << endl;
        // prints the entire matrix by row
        // traverse the matrix vector
        for (int i = 0; i < m_row; i++)
        {
            cout << "[";
            for (int j = 0; j < m_col; j++)
            {
                // input each value of the matrix
                cout << " " << matrix[i][j] << " "; 
            } 
            cout << "]" << endl;
        }           
    }
    void addMatrix(Matrix & rhsMatrix) 
    {
        // check to see if both matrix are the same size
        if (m_row == rhsMatrix.m_row && m_col == rhsMatrix.m_col) {
            // traverse the matrix, add the values at each index of the current and rhs matrix
            for (int i = 0; i < m_row; i++)
            {
                for (int j = 0; j < m_col; j++)
                {
                    matrix[i][j] = matrix[i][j] + rhsMatrix.matrix[i][j];
                }
            }
        }
    }
    void subtractMatrix(Matrix & rhsMatrix) 
    {
        // check to see if both matrix are the same size
        if (m_row == rhsMatrix.m_row && m_col == rhsMatrix.m_col) {
            // traverse and subtract the value of the rhsMatrix from the current matrix
            for (int i = 0; i < m_row; i++)
            {
                for (int j = 0; j < m_col; j++)
                {
                    matrix[i][j] = matrix[i][j] - rhsMatrix.matrix[i][j];
                }
            }
        }
    }
    void scalarMultiplyMatrix(int scalar)
    {
        // traverse matrix, multiply each element by the scalar
        for (int i = 0; i < m_row; i++) 
        {
            for (int j = 0; j < m_col; j++)
            {
                matrix[i][j] = matrix[i][j] * scalar;
            }
        }
    }
    Matrix multiplyMatrix(Matrix & rhsMatrix) 
    {
        // check if the number of columns in the current matrix equals the number of rows in the rhsMatrix, if they aren't we don't multiply
        if (m_col != rhsMatrix.m_row) {
            return *this; // return the original matrix
        }
        Matrix result(m_row, rhsMatrix.m_col); // new matrix, holds values from matrix multiplication, uses row # from the current matrix and col # from the rhsMatrix
        for (int i = 0; i < m_row; i++) 
        {
            for (int j = 0; j < rhsMatrix.m_col; j++) 
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < m_col; k++)
                {
                    result.matrix[i][j] += matrix[i][k] * rhsMatrix.matrix[k][j];
                }
            }
        }
        return result; // return the new matrix
    }
    Matrix transposeMatrix() 
    {
        // flips matrix, rows become columns, columns become rows 
        Matrix result(m_col, m_row); // new matrix, holds values from matrix transposition
        for (int i = 0; i < m_col; i++)
        {
            for (int j = 0; j < m_row; j++)
            {
                result.matrix[i][j] = matrix[j][i];
            }
        }
        return result;
    }
private:
    int m_row; // number of rows in the matrix
    int m_col; // number of columns in the matrix
    vector<vector<int>> matrix; // matrix
};

int main()
{
    // create the matrix objects
    Matrix A(2, 2);
    Matrix B(2, 3);
    Matrix C(2, 3);
    // fill each matrix with the data
    A.fillMatrix();
    B.fillMatrix();
    C.fillMatrix();
    A.printMatrix();
    B.printMatrix();
    C.printMatrix();
    // perform the steps of the equation
    B.scalarMultiplyMatrix(3);
    B.printMatrix();
    C = C.transposeMatrix();
    C.printMatrix();
    B = B.multiplyMatrix(C);
    B.printMatrix();
    A.addMatrix(B);
    // print the result
    A.printMatrix();
}