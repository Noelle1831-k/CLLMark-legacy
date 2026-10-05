int main() {
    FinanceTracker tracker;
    int choice;
    do {
        cout << "\n--- Finance Tracker Lite ---\n";
        cout << "1. Add Transaction\n";
        cout << "2. View Financial Summary\n";
        cout << "3. View Category Breakdown\n";
        cout << "4. Set Budget\n";
        cout << "5. Export Transactions\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                double amount;
                string description, category;
                char type;
                cout << "Enter amount: ";
                cin >> amount;
                cin.ignore();
                cout << "Enter description: ";
                getline(cin, description);
                cout << "Enter category (e.g., food, transport): ";
                getline(cin, category);
                cout << "Enter type (i for income, e for expense): ";
                cin >> type;
                tracker.addTransaction(amount, description, category, type);
                break;
            }
            case 2:
                tracker.viewSummary();
                break;
            case 3:
                tracker.viewCategoryBreakdown();
                break;
            case 4: {
                string category;
                double budgetAmount;
                cout << "Enter category for budget: ";
                cin.ignore();
                getline(cin, category);
                cout << "Enter budget amount: ";
                cin >> budgetAmount;
                tracker.setBudget(category, budgetAmount);
                break;
            }
            case 5:
                tracker.exportTransactions();
                break;
            case 6:
                cout << "Exiting Finance Tracker Lite. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}