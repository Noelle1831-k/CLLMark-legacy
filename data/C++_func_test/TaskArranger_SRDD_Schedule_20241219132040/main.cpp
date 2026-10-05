int main() {
    TaskManager taskManager;
    NotificationManager notificationManager;
    DayOverview dayOverview;
    thread reminderThread(checkReminders, ref(taskManager), ref(notificationManager));
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string title, category;
                int hour, minute;
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter task category (Work/Personal/Custom): ";
                getline(cin, category);
                cout << "Enter task time (hour minute): ";
                cin >> hour >> minute;
                Task newTask(title, category, hour, minute);
                taskManager.addTask(newTask);
                notificationManager.setReminder(newTask);
                break;
            }
            case 2: {
                int id;
                cout << "Enter task ID to remove: ";
                cin >> id;
                taskManager.removeTask(id);
                break;
            }
            case 3:
                taskManager.listTasks();
                break;
            case 4: {
                string category;
                cout << "Enter category to filter: ";
                cin.ignore();
                getline(cin, category);
                taskManager.getTasksByCategory(category);
                break;
            }
            case 5:
                taskManager.sortTasksByTime();
                break;
            case 6:
                dayOverview.generateOverview(taskManager);
                break;
            case 7:
                cout << "Exiting TaskArranger. Goodbye!\n";
                reminderThread.detach();
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}