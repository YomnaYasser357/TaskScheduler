#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

// Task Structure
struct Task {
    string name;
    int priority;

    // Constructor
    Task(string n, int p) : name(n), priority(p) {}

    // Overload operator for priority queue (higher priority first)
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

class TaskScheduler {
private:
    priority_queue<Task> tasks;

public:
    // Add a task
    void addTask(string name, int priority) {
        tasks.push(Task(name, priority));
    }

    // Remove the highest priority task
    void completeTask() {
        if (!tasks.empty()) {
            cout << "Completed Task: " << tasks.top().name << endl;
            tasks.pop();
        } else {
            cout << "No tasks to complete!" << endl;
        }
    }

    // Display all tasks
    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }
        
        priority_queue<Task> temp = tasks;
        cout << "Task List (Highest Priority First):" << endl;
        while (!temp.empty()) {
            cout << "- " << temp.top().name << " (Priority: " << temp.top().priority << ")" << endl;
            temp.pop();
        }
    }
};

int main() {
    TaskScheduler scheduler;
    int choice;
    string name;
    int priority;
    
    while (true) {
        cout << "\nTask Scheduler Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Complete Task" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task name: ";
                cin >> ws; // To ignore newline character
                getline(cin, name);
                cout << "Enter task priority (Higher number = Higher priority): ";
                cin >> priority;
                scheduler.addTask(name, priority);
                break;
            case 2:
                scheduler.completeTask();
                break;
            case 3:
                scheduler.displayTasks();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
