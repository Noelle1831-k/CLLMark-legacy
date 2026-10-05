int main() {
    User user("John Doe");
    GoalTracker tracker;
    int choice;
    do {
        cout << "Financial Goal Manager\n";
        cout << "1. Add Goal\n";
        cout << "2. View Goals\n";
        cout << "3. Update Goal\n";
        cout << "4. Get Advice\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name;
                double target, current;
                int deadline;
                cout << "Enter goal name: ";
                cin >> name;
                cout << "Enter target amount: ";
                cin >> target;
                cout << "Enter current amount: ";
                cin >> current;
                cout << "Enter deadline (in days): ";
                cin >> deadline;
                user.addGoal(name, target, current, deadline);
                break;
            }
            case 2:
                user.viewGoals();
                break;
            case 3: {
                string name;
                double amount;
                cout << "Enter goal name to update: ";
                cin >> name;
                cout << "Enter amount to add: ";
                cin >> amount;
                user.updateGoal(name, amount);
                break;
            }
            case 4:
                tracker.provideAdvice(user);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}