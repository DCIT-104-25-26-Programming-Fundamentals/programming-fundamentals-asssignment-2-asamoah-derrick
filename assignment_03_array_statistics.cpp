// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

double calculateSum(double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(double arr[], int n)
{
    return calculateSum(arr, n) / n;
}

double calculateMax(double arr[], int n)
{
    double biggest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > biggest)
        {
            biggest = arr[i];
        }
    }
    return biggest;
}

double calculateMin(double arr[], int n)
{
    double smallest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int main()
{
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: The count must be a positive integer." << endl;
        return 0;
    }

    double arr[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    double sum = calculateSum(arr, n);
    double avg = calculateAverage(arr, n);
    double maxNum = calculateMax(arr, n);
    double minNum = calculateMin(arr, n);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << maxNum << endl;
    cout << "Minimum: " << minNum << endl;

    return 0;
}
