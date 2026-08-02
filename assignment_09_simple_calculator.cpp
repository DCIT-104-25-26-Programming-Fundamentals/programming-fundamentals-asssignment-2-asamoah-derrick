// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    double result = a + b;
    return result;
}

double subtract(double a, double b) {
    double result = a - b;
    return result;
}

double multiply(double a, double b) {
    double result = a * b;
    return result;
}

double divide(double a, double b) {
    double result = a / b;
    return result;
}

int mod(int a, int b) {
    int result = a % b;
    return result;
}

double power(double base, double exp) {
    double result = pow(base, exp);
    return result;
}

void menu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    int choice = 0;

    while (choice != 7) {
        menu();
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin, garbage);
            cout << "Error: Invalid choice." << endl << endl;
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice." << endl << endl;
            continue;
        }

        cout << fixed << setprecision(2);

        if (choice == 5) {
            int num1, num2;
            cout << "Enter first number : ";
            cin >> num1;
            if (cin.fail()) {
                cin.clear();
                string junk;
                getline(cin, junk);
                cout << "Error: Invalid number." << endl << endl;
                continue;
            }
            cout << "Enter second number: ";
            cin >> num2;
            if (cin.fail()) {
                cin.clear();
                string junk;
                getline(cin, junk);
                cout << "Error: Invalid number." << endl << endl;
                continue;
            }

            if (num2 == 0) {
                cout << "Error: Cannot divide by zero." << endl << endl;
                continue;
            }

            cout << "Result: " << num1 << " % " << num2 << " = " << mod(num1, num2) << endl << endl;

        } else {
            double num1, num2;
            cout << "Enter first number : ";
            cin >> num1;
            if (cin.fail()) {
                cin.clear();
                string junk;
                getline(cin, junk);
                cout << "Error: Invalid number." << endl << endl;
                continue;
            }
            cout << "Enter second number: ";
            cin >> num2;
            if (cin.fail()) {
                cin.clear();
                string junk;
                getline(cin, junk);
                cout << "Error: Invalid number." << endl << endl;
                continue;
            }

            if (choice == 4 && num2 == 0) {
                cout << "Error: Cannot divide by zero." << endl << endl;
                continue;
            }

            double answer;
            string symbol;

            if (choice == 1) {
                answer = add(num1, num2);
                symbol = "+";
            }
            if (choice == 2) {
                answer = subtract(num1, num2);
                symbol = "-";
            }
            if (choice == 3) {
                answer = multiply(num1, num2);
                symbol = "*";
            }
            if (choice == 4) {
                answer = divide(num1, num2);
                symbol = "/";
            }
            if (choice == 6) {
                answer = power(num1, num2);
                symbol = "^";
            }

            cout << "Result: " << num1 << " " << symbol << " " << num2 << " = " << answer << endl << endl;
        }
    }

    return 0;
}
