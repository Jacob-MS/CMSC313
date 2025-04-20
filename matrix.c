#include <stdio.h>
#define DEFAULT_SIZE 5

void fillMatrix(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col);
void displayMatrix(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col);
void addMatrix(int matrix1[DEFAULT_SIZE][DEFAULT_SIZE], int matrix2[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col);
void subtractMatrix(int matrix1[DEFAULT_SIZE][DEFAULT_SIZE], int matrix2[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col);
void scalarMultiplyMatrix(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col, int scalar);
void multiplyMatrix(int newMatrix[DEFAULT_SIZE][DEFAULT_SIZE], const int matrix1[DEFAULT_SIZE][DEFAULT_SIZE], const int matrix2[DEFAULT_SIZE][DEFAULT_SIZE], int row1, int col1, int col2);
void transposeMatrix(int newMatrix[DEFAULT_SIZE][DEFAULT_SIZE], const int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col);

int main() {
    
    int aRow = 2, aCol = 2;
    int bRow = 2, bCol = 3;
    int cRow = 2, cCol = 3;
    int A[aRow][aCol], B[bRow][bCol], C[cRow][cCol];
    int scalar = 3;

    // fill the matrixs
    fillMatrix(A, aRow, aCol);
    fillMatrix(B, bRow, bCol);
    fillMatrix(C, cRow, cCol);
    // display the matrixs
    displayMatrix(A, aRow, aCol);
    displayMatrix(B, bRow, bCol);
    displayMatrix(C, cRow, cCol);

    // order of operations for the provided test equation

    // scalar multiply B
    scalarMultiplyMatrix(B, bRow, bCol, scalar);
    displayMatrix(B, bRow, bCol);
    // transpose C
    transposeMatrix(C, C, cRow, cCol);
    displayMatrix(C, cRow, cCol);
    // Multiply B and C
    multiplyMatrix(B, B, C, bRow, bCol, cCol);
    displayMatrix(B, bRow, bCol);
    // add A and B
    addMatrix(A, B, aRow, aCol);
    displayMatrix(A, aRow, aCol);
    return 0;
}

void fillMatrix(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col) {
    printf("Enter elements of matrix(%dx%d):\n", row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void displayMatrix(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col) {
    printf("matrix:\n");
    for (int i = 0; i < row; i++) 
    {
        printf("[");
        for (int j = 0; j < col; j++)
        {
            printf(" %d ", matrix[i][j]);
        }   
        printf("]\n");
    }
}
void addMatrix(int matrix1[DEFAULT_SIZE][DEFAULT_SIZE], int matrix2[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
void subtractMatrix(int matrix1[DEFAULT_SIZE][DEFAULT_SIZE], int matrix2[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix1[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
void scalarMultiplyMatrix(int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col, int scalar) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = matrix[i][j] * scalar;
        }
    }
}
void multiplyMatrix(int newMatrix[DEFAULT_SIZE][DEFAULT_SIZE], const int matrix1[DEFAULT_SIZE][DEFAULT_SIZE], const int matrix2[DEFAULT_SIZE][DEFAULT_SIZE], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++) 
        {
            newMatrix[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                newMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }    
}
void transposeMatrix(int newMatrix[DEFAULT_SIZE][DEFAULT_SIZE], const int matrix[DEFAULT_SIZE][DEFAULT_SIZE], int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            newMatrix[j][i] = matrix[i][j];
        }
    }
}