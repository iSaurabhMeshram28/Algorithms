#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string name;
    int priority;
};

void insertionSort(std::vector<Task>& tasks) {
    int n = tasks.size();

    for (int i = 1; i < n; ++i) {
        Task key = tasks[i];
        int j = i - 1;

        // Move tasks with higher priority to one position ahead of their current position
        while (j >= 0 && tasks[j].priority < key.priority) {
            tasks[j + 1] = tasks[j];
            --j;
        }

        tasks[j + 1] = key;
    }
}

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "\nTask List (sorted by priority):\n";
    for (const auto& task : tasks) {
        std::cout << "Task: " << task.name << ", Priority: " << task.priority << "\n";
    }
}

int main() {
    std::vector<Task> tasks;

    std::cout << "Enter tasks and priorities (type 'end' for task name to end input):\n";
    while (true) {
        Task task;
        std::cout << "Task: ";
        std::cin >> task.name;

        if (task.name == "end") {
            break;
        }

        std::cout << "Priority: ";
        std::cin >> task.priority;

        tasks.push_back(task);
    }

    insertionSort(tasks);
    displayTasks(tasks);

    return 0;
}
