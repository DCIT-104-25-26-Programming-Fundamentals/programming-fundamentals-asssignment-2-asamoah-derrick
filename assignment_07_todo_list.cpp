// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void printMenu()
{
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

bool readInt(int &value)
{
    cin >> value;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void addTask(vector<string> &tasks)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string task;
    cout << "Enter task: ";
    getline(cin, task);
    todo.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks(vector<string> &todo)
{
    if (todo.empty())
    {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    int index = 1;
    for (const string &task : tasks)
    {
        cout << index++ << ". " << task << endl;
    }
}

void deleteTask(vector<string> &tasks)
{
    if (tasks.empty())
    {
        cout << "Your to-do list is empty. Nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);

    int pick;
    cout << "Enter task number to delete: ";
    if (!readInt(pick))
    {
        cout << "Error: invalid task number." << endl;
        return;
    }

    int idx = pick - 1;
    if (idx < 0 || idx >= static_cast<int>(tasks.size()))
    {
        cout << "Error: invalid task number." << endl;
        return;
    }

    string gone = tasks[idx];
    tasks.erase(tasks.begin() + idx);
    cout << "Task \"" << gone << "\" has been removed." << endl;
}

int main()
{
    vector<string> tasks;
    int option;

    while (true)
    {
        printMenu();
        cout << "Enter your choice (1-4): ";
        if (!readInt(option))
        {
            cout << "Error: invalid choice." << endl;
            continue;
        }

        if (option == 1)
        {
            addTask(tasks);
        }
        else if (option == 2)
        {
            viewTasks(tasks);
        }
        else if (option == 3)
        {
            deleteTask(tasks);
        }
        else if (option == 4)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Error: invalid choice." << endl;
        }
    }

    return 0;
}