int main() {
    TaskManager taskManager;
    Reminder reminder;
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                taskManager.addTask();
                break;
            }
            case 2: {
                int id;
                cout << "Enter Task ID to update: ";
                cin >> id;
                taskManager.updateTask(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter Task ID to mark as complete: ";
                cin >> id;
                taskManager.markComplete(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Task ID to delete: ";
                cin >> id;
                taskManager.deleteTask(id);
                break;
            }
            case 5: {
                string query;
                cout << "Enter title or category to search: ";
                cin.ignore();
                getline(cin, query);
                taskManager.searchTask(query);
                break;
            }
            case 6: {
                taskManager.displayTasks();
                break;
            }
            case 7: {
                taskManager.categorizeTasks();
                break;
            }
            case 8: {
                int id;
                cout << "Enter Task ID to set reminder: ";
                cin >> id;
                reminder.setReminder(id);
                break;
            }
            case 9: {
                cout << "Exiting the application. Goodbye!\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
    return 0;
}