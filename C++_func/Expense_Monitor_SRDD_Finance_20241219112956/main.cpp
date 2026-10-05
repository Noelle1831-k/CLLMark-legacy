int main() {
    User user("John Doe");
    ExpenseTracker tracker;
    int choice = -1;
    while (choice != 0) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addExpense(tracker, user);
                break;
            case 2:
                addCategory(user);
                break;
            case 3:
                tracker.generateUserReport(user);
                break;
            case 4: {
                Reminder reminder(user);
                reminder.checkBudgets();
                break;
            }
            case 0:
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}