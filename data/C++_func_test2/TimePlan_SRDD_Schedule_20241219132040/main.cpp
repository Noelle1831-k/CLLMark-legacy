int main() {
    Schedule schedule;
    int choice;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string title, description, deadline;
                double timeAllocated;
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter task deadline (YYYY-MM-DD): ";
                cin >> deadline;
                cout << "Enter time allocated (in hours): ";
                cin >> timeAllocated;
                schedule.addTask(title, description, deadline, timeAllocated);
                break;
            }
            case 2: {
                int id;
                cout << "Enter task ID to remove: ";
                cin >> id;
                schedule.removeTask(id);
                break;
            }
            case 3:
                schedule.displayTasks();
                break;
            case 4:
                schedule.generateReport();
                break;
            case 5:
                cout << "Exiting TimePlan. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}