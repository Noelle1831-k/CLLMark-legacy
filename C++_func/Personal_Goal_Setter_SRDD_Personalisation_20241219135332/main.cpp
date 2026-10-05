int main() {
    User user;
    Reminder reminder;
    ProgressTracker tracker;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string name, category;
                double target;
                cout << "Enter goal name: ";
                getline(cin, name);
                cout << "Enter goal category (e.g., Fitness, Career): ";
                getline(cin, category);
                cout << "Enter target value: ";
                cin >> target;
                user.addGoal(name, category, target);
                break;
            }
            case 2: {
                user.displayGoals();
                break;
            }
            case 3: {
                string name;
                double progress;
                cout << "Enter goal name to update: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter progress value: ";
                cin >> progress;
                user.updateGoalProgress(name, progress);
                break;
            }
            case 4: {
                string name;
                int hours;
                cout << "Enter goal name to set reminder for: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter reminder time in hours: ";
                cin >> hours;
                reminder.addReminder(name, hours);
                break;
            }
            case 5: {
                tracker.generateReport(user.getGoals());
                break;
            }
            case 6: {
                cout << "Exiting application. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 6);
    return 0;
}