#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task Class
class Task {
private:
    int id;
    string title;
    string description;
    bool completed;

public:
    // Constructor
    Task(int id, string title, string description) {
        this->id = id;
        this->title = title;
        this->description = description;
        this->completed = false;
    }

    // Mark as completed
    void markCompleted() {
        completed = true;
    }

    // Display task details
    void displayTask() {
        cout << "Task ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Status: " << (completed ? "Completed" : "Pending") << endl;
        cout << "----------------------------" << endl;
    }

    // Getters
    int getId() { return id; }
    bool isCompleted() { return completed; }
};


// Main Program
int main() {
    vector<Task> tasks;
    int choice;
    int nextId = 1;

    while (true) {
        cout << "\n===== TO-DO LIST MANAGER =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View All Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title, description;
            cout << "Enter Task Title: ";
            getline(cin, title);
            cout << "Enter Task Description: ";
            getline(cin, description);

            Task newTask(nextId, title, description);
            tasks.push_back(newTask);
            cout << "Task Added Successfully! [ID: " << nextId << "]\n";
            nextId++;
        }
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No Tasks Available.\n";
            } else {
                cout << "\n--- Task List ---\n";
                for (auto &task : tasks) {
                    task.displayTask();
                }
            }
        }
        else if (choice == 3) { // Mark as completed
            int id;
            cout << "Enter Task ID To Mark As Completed: ";
            cin >> id;

            bool found = false;
            for (auto &task : tasks) {
                if (task.getId() == id) {
                    task.markCompleted();
                    cout << "Task " << id << " Marked As Completed!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Task Not Found!\n";
        }
        else if (choice == 4) { // Delete task
            int id;
            cout << "Enter Task ID To Delete: ";
            cin >> id;

            bool found = false;
            for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                if (it->getId() == id) {
                    tasks.erase(it);
                    cout << "Task " << id << " Deleted Successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Task Not Found!\n";
        }
        else if (choice == 5) {
            cout << "Exiting Program. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid Choice! Try Again.\n";
        }
    }

    return 0;
}