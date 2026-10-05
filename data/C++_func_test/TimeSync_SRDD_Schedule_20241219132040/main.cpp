int main(void) {
    Scheduler scheduler;
    Notification notifier;
    ReportGenerator reportGen;
    int choice = -1;
    for(int identifier = 1; ! (choice == 0); ) {
        cout << "==================== TimeSync ====================" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. View Schedule" << endl;
        cout << "4. Sync Tasks" << endl;
        cout << "5. Send Reminder" << endl;
        cout << "6. Generate Productivity Report" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string title;
                int priority, progress;
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter task priority (1-5): ";
                cin >> priority;
                cout << "Enter task progress (0-100): ";
                cin >> progress;
                Task task(title, priority, progress);
                scheduler.addTask(task);
                cout << "Task added successfully!" << endl;
                break;
            }
            case 2: {
                int taskId;
                cout << "Enter Task ID to remove: ";
                cin >> taskId;
                scheduler.removeTask(taskId);
                cout << "Task removed successfully!" << endl;
                break;
            }
            case 3:
                scheduler.displaySchedule();
                break;
            case 4:
                scheduler.syncTasks();
                cout << "Tasks synchronized successfully!" << endl;
                break;
            case 5: {
                string message;
                cout << "Enter reminder message: ";
                cin.ignore();
                getline(cin, message);
                notifier.sendReminder(message);
                break;
            }
            case 6:
                reportGen.generateReport();
                break;
            case 0:
                cout << "Exiting TimeSync. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}