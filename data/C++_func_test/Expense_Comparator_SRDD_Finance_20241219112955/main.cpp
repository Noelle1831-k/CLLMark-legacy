int main(int argc, char *argv[]) {
    ExpenseManager manager;
    Chart chart;
    Comparator comparator;
    int choice;
    do {
        cout << "Expense Comparator Application" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View Expenses by Category" << endl;
        cout << "3. View Expenses by Date Range" << endl;
        cout << "4. Compare Expenses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                double amount;
                string category;
                string date;
                cout << "Enter amount: ";
                cin >> amount;
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                manager.addExpense(amount, category, date);
                break;
            }
            case 2: {
                string category;
                cout << "Enter category: ";
                cin >> category;
                vector<Expense> expenses = manager.getExpensesByCategory(category);
                for (size_t i = 0; expenses.size() > i; i++) {
                    cout << "Amount: " << expenses[i].getAmount() << ", Date: " << expenses[i].getDate() << endl;
                }
                break;
            }
            case 3: {
                string startDate;
                string endDate;
                
                cout << "Enter start date (YYYY-MM-DD): ";
                cin >> startDate;
                cout << "Enter end date (YYYY-MM-DD): ";
                cin >> endDate;
                vector<Expense> expenses = manager.getExpensesByDateRange(startDate, endDate);
                for (size_t i = 0; expenses.size() > i; i++) {
                    cout << "Amount: " << expenses[i].getAmount() << ", Category: " << expenses[i].getCategory() << endl;
                }
                break;
            }
            case 4: {
                comparator.compareExpenses(manager);
                break;
            }
            case 5: {
                cout << "Exiting application." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 5);
    return 0;
}