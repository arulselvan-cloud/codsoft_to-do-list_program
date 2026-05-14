#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for task details
struct Task {
    string name;
    bool completed;
};

// Vector to store tasks
vector<Task> tasks;

// Pause function
void pauseScreen() {
    cin.ignore(1000, '\n');
    cout << "\nPress Enter to continue...";
    cin.get();
}

// Function to add task
void addTask() {

    Task t;

    cout << "\nEnter task: ";

    cin.ignore(1000, '\n');
    getline(cin, t.name);

    t.completed = false;

    tasks.push_back(t);

    cout << "Task added successfully!\n";
}

// Function to view tasks
void viewTasks() {

    if(tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n========== TO-DO LIST ==========\n";

    for(int i = 0; i < tasks.size(); i++) {

        cout << i + 1 << ". "
             << tasks[i].name;

        if(tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";

        cout << endl;
    }
}

// Function to mark task as completed
void completeTask() {

    if(tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    viewTasks();

    int taskNumber;

    cout << "\nEnter task number to mark as completed: ";
    cin >> taskNumber;

    if(taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks[taskNumber - 1].completed = true;

    cout << "Task marked as completed!\n";
}

// Function to remove task
void removeTask() {

    if(tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    viewTasks();

    int taskNumber;

    cout << "\nEnter task number to remove: ";
    cin >> taskNumber;

    if(taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + (taskNumber - 1));

    cout << "Task removed successfully!\n";
}

// Main function
int main() {

    int choice;

    do {

        cout << "\n==============================";
        cout << "\n       TO-DO LIST MANAGER";
        cout << "\n==============================";
        cout << "\n1. Add Task";
        cout << "\n2. View Tasks";
        cout << "\n3. Mark Task as Completed";
        cout << "\n4. Remove Task";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";

        cin >> choice;

        switch(choice) {

            case 1:
                addTask();
                pauseScreen();
                break;

            case 2:
                viewTasks();
                pauseScreen();
                break;

            case 3:
                completeTask();
                pauseScreen();
                break;

            case 4:
                removeTask();
                pauseScreen();
                break;

            case 5:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
                pauseScreen();
        }

    } while(choice != 5);

    return 0;
}
