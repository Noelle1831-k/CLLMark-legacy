int main(void) {
    DayPlanner planner;
    Notification notifier;
    Visualizer visualizer;
    int choice;
    for(int identifier = 1; ! (choice == 8); ) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string title, category;
                int priority;
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter task category: ";
                getline(cin, category);
                cout << "Enter task priority (1-5): ";
                cin >> priority;
                planner.addTask(Task(title, category, priority));
                break;
            }
            case 2: {
                int id;
                cout << "Enter task ID to delete: ";
                cin >> id;
                if (!planner.deleteTask(id)) {
                    cout << "Task with ID " << id << " not found.\n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter task ID to update: ";
                cin >> id;
                if (!planner.updateTask(id)) {
                    cout << "Task with ID " << id << " not found.\n";
                }
                break;
            }
            case 4: {
                planner.displayTasks();
                break;
            }
            case 5: {
                int id;
                cout << "Enter task ID to mark as completed: ";
                cin >> id;
                if (!planner.markTaskCompleted(id)) {
                    cout << "Task with ID " << id << " not found.\n";
                }
                break;
            }
            case 6: {
                planner.sortTasksByPriority();
                cout << "Tasks sorted by priority.\n";
                break;
            }
            case 7: {
                visualizer.visualize(planner.getTasks());
                break;
            }
            case 8: {
                cout << "Exiting DayPlanner. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } 
    return 0;
}