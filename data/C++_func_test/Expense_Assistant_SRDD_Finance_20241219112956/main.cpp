int main(int argc, char *argv[]) {
    ExpenseManager expenseManager;
    Budget budget;
    Visualization visualization;
    Reminder reminder;
    int choice;
    do {
        cout << "\nExpense Assistant Menu:" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. Set Budget Limit" << endl;
        cout << "3. View Spending Report" << endl;
        cout << "4. Check Budget Reminders" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1: {
                double amount;
                string category, date;
                cout << "Enter expense amount: ";
                cin >> amount;
                if (cin.fail()) {
                    cout << "Invalid amount. Please enter a valid number." << endl;
                    clearInputBuffer();
                    break;
                }
                cout << "Enter expense category: ";
                cin >> category;
                cout << "Enter expense date (YYYY-MM-DD): ";
                cin >> date;
                expenseManager.addExpense(Expense(amount, category, date));
                cout << "Expense added successfully!" << endl;
                break;
            }
            case 2: {
                string category;
                double limit;
                cout << "Enter category to set budget limit: ";
                cin >> category;
                cout << "Enter budget limit for " << category << ": ";
                cin >> limit;
                if (cin.fail()) {
                    cout << "Invalid limit. Please enter a valid number." << endl;
                    clearInputBuffer();
                    break;
                }
                budget.setLimit(category, limit);
                cout << "Budget limit set successfully!" << endl;
                break;
            }
            case 3: {
                visualization.generateReport(expenseManager.getExpenses());
                break;
            }
            case 4: {
                reminder.checkReminders(budget, expenseManager);
                break;
            }
            case 5:
                cout << "Exiting Expense Assistant. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}