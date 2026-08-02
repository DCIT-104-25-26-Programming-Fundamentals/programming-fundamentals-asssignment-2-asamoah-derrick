// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    vector<double> grades;
    int id;
};

vector<Student> database;

void clearInput()
{
    cin.clear();
    while (cin.peek() != '\n' && cin.peek() != EOF)
        cin.get();
    cin.get();
}

double average(Student s)
{
    double total = 0;
    int count = 0;
    for (int i = 0; i < s.grades.size(); i++)
    {
        total = total + s.grades[i];
        count++;
    }
    if (count == 0)
        return 0.0;
    return total / count;
}

string gradeString(Student s)
{
    string result = "";
    for (int i = 0; i < s.grades.size(); i++)
    {
        ostringstream temp;
        temp << fixed << setprecision(1) << s.grades[i];
        result = result + temp.str();
        if (i != s.grades.size() - 1)
            result = result + ", ";
    }
    if (result == "")
        result = "none";
    return result;
}

int findStudent(int id)
{
    int found = -1;
    for (int i = 0; i < database.size(); i++)
    {
        if (database[i].id == id)
        {
            found = i;
        }
    }
    return found;
}

void showAverage()
{
    if (database.size() < 1)
    {
        cout << "theres nobody in the system yet\n";
        return;
    }

    cout << "which student id: ";
    int searchId;
    cin >> searchId;

    if (!cin.good())
    {
        clearInput();
        cout << "that wasnt a number\n";
        return;
    }

    int index = findStudent(searchId);
    if (index == -1)
    {
        cout << "no student with id " << searchId << " exists\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << database[index].name << " average is " << average(database[index]) << "\n";
}

void printEveryone()
{
    if (database.size() == 0)
    {
        cout << "nobody here yet\n";
        return;
    }

    cout << "\n";
    for (int x = 0; x < 70; x++)
        cout << "-";
    cout << "\n";

    cout << left;
    cout << setw(18) << "Name";
    cout << setw(10) << "ID";
    cout << setw(28) << "Grades";
    cout << "Avg";
    cout << "\n";

    for (int x = 0; x < 70; x++)
        cout << "-";
    cout << "\n";

    for (int i = 0; i < database.size(); i++)
    {
        cout << fixed << setprecision(2);
        cout << left;
        cout << setw(18) << database[i].name;
        cout << setw(10) << database[i].id;
        cout << setw(28) << gradeString(database[i]);
        cout << average(database[i]);
        cout << "\n";
    }

    for (int x = 0; x < 70; x++)
        cout << "-";
    cout << "\n\n";
}

void registerStudent()
{
    Student fresh;

    cout << "enter name: ";
    getline(cin, fresh.name);

    bool nameEmpty = true;
    for (int i = 0; i < fresh.name.length(); i++)
    {
        if (fresh.name[i] != ' ')
        {
            nameEmpty = false;
            break;
        }
    }
    if (nameEmpty)
    {
        cout << "you gotta type a name\n";
        return;
    }

    cout << "enter id number: ";
    cin >> fresh.id;

    if (!cin.good())
    {
        clearInput();
        cout << "thats not a valid number\n";
        return;
    }

    if (fresh.id < 1)
    {
        cout << "id has to be positive\n";
        return;
    }

    int existing = findStudent(fresh.id);
    if (existing != -1)
    {
        cout << "someone already has that id (" << database[existing].name << ")\n";
        return;
    }

    cout << "how many grades to enter: ";
    int numGrades;
    cin >> numGrades;

    if (!cin.good())
    {
        clearInput();
        cout << "not a number\n";
        return;
    }

    if (numGrades < 1)
    {
        cout << "has to be at least 1\n";
        return;
    }

    for (int i = 0; i < numGrades; i++)
    {
        double g;
        while (true)
        {
            cout << "grade " << i + 1 << ": ";
            cin >> g;

            if (!cin.good())
            {
                clearInput();
                cout << "thats not a number try again\n";
                continue;
            }

            if (g < 0 || g > 100)
            {
                cout << "has to be between 0 and 100 try again\n";
                continue;
            }

            break;
        }
        fresh.grades.push_back(g);
    }

    database.push_back(fresh);
    cout << "added " << fresh.name << " with " << numGrades << " grades\n";
}

int main()
{
    int option = 0;

    cout << "welcome to the student thing\n";

    while (option != 4)
    {
        cout << "\n--- menu ---\n";
        cout << "1 - register student\n";
        cout << "2 - show everyone\n";
        cout << "3 - check average\n";
        cout << "4 - exit\n";
        cout << "> ";

        cin >> option;

        if (!cin.good())
        {
            clearInput();
            cout << "just type a number between 1 and 4\n";
            option = 0;
            continue;
        }

        if (option < 1 || option > 4)
        {
            cout << "thats not on the menu\n";
            continue;
        }

        string junk;
        getline(cin, junk);

        if (option == 1)
            registerStudent();

        if (option == 2)
            printEveryone();

        if (option == 3)
            showAverage();

        if (option == 4)
            cout << "later\n";
    }

    return 0;
}
