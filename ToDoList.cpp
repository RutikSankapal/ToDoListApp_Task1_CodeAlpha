
#include <iostream>
#include <vector>

class TodoList {
private:
    std::vector<std::string> tasks;
    std::vector<bool> completed;

public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
        completed.push_back(false);
        std::cout << "Task added: " << task << std::endl;
    }

    void markAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            completed[index] = true;
            std::cout << "Task marked as completed: " << tasks[index] << std::endl;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void displayTasks() {
        std::cout << "\nCurrent tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << (completed[i] ? "[X] " : "[ ] ");
            std::cout << tasks[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    TodoList todoList;

    char choice;
    do {
        std::cout << "Options:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                {
                    std::string task;
                    std::cout << "Enter task description: ";
                    std::cin.ignore();  // Ignore newline character from previous input
                    std::getline(std::cin, task);
                    todoList.addTask(task);
                    break;
                }
            case '2':
                {
                    int index;
                    std::cout << "Enter task index to mark as completed: ";
                    std::cin >> index;
                    todoList.markAsCompleted(index - 1); // Adjust index to start from 1
                    break;
                }
            case '3':
                todoList.displayTasks();
                break;
            case '4':
                std::cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '4');

    return 0;
}
