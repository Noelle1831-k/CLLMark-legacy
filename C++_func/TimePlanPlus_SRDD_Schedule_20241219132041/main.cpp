int main() {
    Scheduler scheduler;
    ReportGenerator reportGenerator;
    int choice;
    do {
        cout << "\n--- TimePlanPlus ---\n";
        cout << "1. Add Task\n";
        cout << "2. Add Habit\n";
        cout << "3. Add Goal\n";
        cout << "4. View Report\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string title;
                string deadline;
                int timeAllocation;
                cout << "Enter Task Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Deadline (YYYY-MM-DD): ";
                cin >> deadline;
                cout << "Enter Time Allocation (hours): ";
                cin >> timeAllocation;
                scheduler.addTask(Task(title, deadline, timeAllocation));
                break;
            }
            case 2: {
                string name;
                int frequency;
                cout << "Enter Habit Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Frequency (times per week): ";
                cin >> frequency;
                scheduler.addHabit(Habit(name, frequency));
                break;
            }
            case 3: {
                string description;
                string deadline;
                cout << "Enter Goal Description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Enter Deadline (YYYY-MM-DD): ";
                cin >> deadline;
                scheduler.addGoal(Goal(description, deadline));
                break;
            }
            case 4: {
                reportGenerator.generateReport(scheduler);
                break;
            }
            case 5:
                cout << "Exiting TimePlanPlus. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}