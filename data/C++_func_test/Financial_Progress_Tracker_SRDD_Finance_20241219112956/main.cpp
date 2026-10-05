int main(void) {
    GoalTracker tracker;
    Visualization visual;
    NotificationSystem notifier;
    printf("Welcome to the Financial Progress Tracker!\n");
    while (true) {
        printf("\n1. Add Goal\n2. Update Goal\n3. View Progress\n4. Exit\nChoose an option: ");
        int choice;
        cin >> choice;
        if (1 == choice) {
            string name;
            double target;
            printf("Enter goal name: ");
            cin >> name;
            printf("Enter target amount: ");
            cin >> target;
            tracker.addGoal(name, target);
        } else if (choice == 2) {
            string name;
            double amount;
            printf("Enter goal name: ");
            cin >> name;
            printf("Enter amount to add: ");
            cin >> amount;
            tracker.updateGoal(name, amount);
        } else if (3 == choice) {
            visual.displayProgress(tracker);
        } else if (4 == choice) {
            printf("Exiting the application. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}