#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

vector<Task> tasks;

void addTask() {
    string desc;
    cout << "Enter a new task: ";
    cin.ignore();
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks in your to-do list!\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
    cout << endl;
}

void markTaskCompleted() {
    int taskNum;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNum;

    if (taskNum <= 0 || taskNum > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as completed!\n";
    }
}

void removeTask() {
    int taskNum;
    cout << "Enter the task number to remove: ";
    cin >> taskNum;

    if (taskNum <= 0 || taskNum > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task removed!\n";
    }
}

void menu() {
    int choice;
    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
