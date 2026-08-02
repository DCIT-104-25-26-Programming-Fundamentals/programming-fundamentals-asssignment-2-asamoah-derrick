// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

void getMatrix(int mat[MAX][MAX], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void showMatrix(int mat[MAX][MAX], int r, int c, string label)
{
    cout << "\n"
         << label << ":" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void doTranspose(int mat[MAX][MAX], int r, int c, int res[MAX][MAX])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res[j][i] = mat[i][j];
        }
    }
}

void doAddition(int a[MAX][MAX], int b[MAX][MAX], int r, int c, int res[MAX][MAX])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void doMultiplication(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int c2, int res[MAX][MAX])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            int sum = 0;
            for (int k = 0; k < c1; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = sum;
        }
    }
}

void runPartA()
{
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    int m[MAX][MAX], res[MAX][MAX];
    getMatrix(m, r, c);
    showMatrix(m, r, c, "Original Matrix");
    doTranspose(m, r, c, res);
    showMatrix(res, c, r, "Transposed Matrix");
}

void runPartB()
{
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    int m1[MAX][MAX], m2[MAX][MAX], res[MAX][MAX];
    cout << "Matrix A:" << endl;
    getMatrix(m1, r, c);
    cout << "Matrix B:" << endl;
    getMatrix(m2, r, c);

    doAddition(m1, m2, r, c, res);
    showMatrix(m1, r, c, "Matrix A");
    showMatrix(m2, r, c, "Matrix B");
    showMatrix(res, r, c, "A + B");
}

void runPartC()
{
    int r1, c1, c2;
    cout << "Enter rows of Matrix A: ";
    cin >> r1;
    cout << "Enter columns of Matrix A (= rows of Matrix B): ";
    cin >> c1;
    cout << "Enter columns of Matrix B: ";
    cin >> c2;

    int m1[MAX][MAX], m2[MAX][MAX], res[MAX][MAX];
    cout << "Matrix A:" << endl;
    getMatrix(m1, r1, c1);
    cout << "Matrix B:" << endl;
    getMatrix(m2, c1, c2);

    doMultiplication(m1, m2, r1, c1, c2, res);
    showMatrix(m1, r1, c1, "Matrix A");
    showMatrix(m2, c1, c2, "Matrix B");
    showMatrix(res, r1, c2, "A x B");
}

int main()
{
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Choose an operation (1-3): ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        runPartA();
    }
    else if (choice == 2)
    {
        runPartB();
    }
    else if (choice == 3)
    {
        runPartC();
    }
    else
    {
        cout << "Error: invalid choice." << endl;
    }

    return 0;
}
