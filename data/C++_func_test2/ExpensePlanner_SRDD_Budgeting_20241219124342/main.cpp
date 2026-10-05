int main() {
    ExpenseManager expenseManager;
    Budget budget;
    NotificationManager notificationManager;
    Visualization visualization;
    int choice;
    do {
        cout << "\nExpensePlanner Menu:\n";
        cout << "1. Set Budget\n";
        cout << "2. Add Expense\n";
        cout << "3. View Expenses\n";
        cout << "4. Generate Report\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                double totalBudget;
                cout << "Enter your total budget: ";
                cin >> totalBudget;
                budget.setTotalBudget(totalBudget);
                break;
            }
            case 2: {
                double amount;
                string category, date, description;
                cout << "Enter expense amount: ";
                cin >> amount;
                cout << "Enter expense category: ";
                cin >> category;
                cout << "Enter expense date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter expense description: ";
                cin.ignore();
                getline(cin, description);
                Expense expense(expenseManager.generateExpenseID(), amount, category, date, description);
                expenseManager.addExpense(expense);
                budget.updateSpentAmount(amount);
                if (budget.checkLimitExceeded()) {
                    notificationManager.sendNotification("Budget limit exceeded!");
                }
                break;
            }
            case 3: {
                expenseManager.displayExpenses();
                break;
            }
            case 4: {
                visualization.generateSummary(expenseManager.getExpenses());
                break;
            }
            case 5: {
                cout << "Exiting ExpensePlanner. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 5);
    return 0;
}