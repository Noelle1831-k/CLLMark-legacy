int main() {
    TaskManager manager;
    Visualizer visualizer;
    Reminder reminder;
    FileHandler fileHandler;
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            string name, timeSlot;
            int priority;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter task priority (1-5): ";
            cin >> priority;
            cout << "Enter time slot (e.g., 14:00-15:00): ";
            cin.ignore();
            getline(cin, timeSlot);
            Task newTask(name, priority, timeSlot);
            manager.addTask(newTask);
            reminder.setReminder(newTask);
        } else if (choice == 2) {
            int id;
            cout << "Enter task ID to delete: ";
            cin >> id;
            manager.deleteTask(id);
        } else if (choice == 3) {
            int id;
            cout << "Enter task ID to edit: ";
            cin >> id;
            manager.editTask(id);
        } else if (choice == 4) {
            manager.displayTasks();
            visualizer.drawSchedule(manager.getAllTasks());
        } else if (choice == 5) {
            fileHandler.saveTasks(manager.getAllTasks());
        } else if (choice == 6) {
            vector<Task> loadedTasks = fileHandler.loadTasks();
            manager.loadTasks(loadedTasks);
        } else if (choice == 7) {
            cout << "Exiting Task Organizer. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}