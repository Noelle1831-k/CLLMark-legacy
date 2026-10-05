int main() {
    User user("Default User");
    RecommendationEngine recommender;
    ReminderSystem reminder;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string taskName, dueDate;
                int priority, duration;
                cout << "Enter task name: ";
                getline(cin, taskName);
                cout << "Enter due date (YYYY-MM-DD): ";
                getline(cin, dueDate);
                cout << "Enter priority (1-5): ";
                cin >> priority;
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                user.addTask(Task(taskName, dueDate, priority, duration));
                break;
            }
            case 2: {
                string taskName;
                cout << "Enter the name of the task to remove: ";
                cin.ignore();
                getline(cin, taskName);
                user.removeTask(taskName);
                break;
            }
            case 3:
                user.displayAllTasks();
                break;
            case 4:
                recommender.generateRecommendations(user);
                break;
            case 5:
                reminder.sendReminder(user);
                break;
            case 6:
                cout << "Exiting TimeTracker. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}