int main() {
    GoalTracker tracker;
    Visualization visual;
    NotificationSystem notifier;
    cout << "Welcome to the Financial Progress Tracker!" << endl;
    while (true) {
        cout << "\n1. Add Goal\n2. Update Goal\n3. View Progress\n4. Exit\nChoose an option: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            string name;
            double target;
            cout << "Enter goal name: ";
            cin >> name;
            cout << "Enter target amount: ";
            cin >> target;
            tracker.addGoal(name, target);
        } else if (choice == 2) {
            string name;
            double amount;
            cout << "Enter goal name: ";
            cin >> name;
            cout << "Enter amount to add: ";
            cin >> amount;
            tracker.updateGoal(name, amount);
        } else if (choice == 3) {
            visual.displayProgress(tracker);
        } else if (choice == 4) {
            cout << "Exiting the application. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}