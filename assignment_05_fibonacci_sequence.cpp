// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void showFib(int n) {
    long t1 = 0, t2 = 1;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << t1 << " ";
        long next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
    cout << endl;
}

bool checkFib(long num) {
    if (num < 0) {
        return false;
    }

    long t1 = 0, t2 = 1;
    while (t1 < num) {
        long next = t1 + t2;
        t1 = t2;
        t2 = next;
    }

    if (t1 == num) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int count;
    cout << "How many terms? ";
    cin >> count;

    if (count <= 0) {
        cout << "Error: the number of terms must be a positive integer." << endl;
        return 0;
    }
    
    showFib(count);

    long userNum;
    cout << "Enter a number to check: ";
    cin >> userNum;

    if (checkFib(userNum)) {
        cout << userNum << " is a Fibonacci number." << endl;
    } else {
        cout << userNum << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
