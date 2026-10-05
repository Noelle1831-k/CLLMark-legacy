void BudgetMonitor::displayDashboard() {
    int choice = 0;
    do {
        cout << "=== BudgetMonitor Dashboard ===" << endl;
        cout << "1. Add Transaction" << endl;
        cout << "2. View Categories" << endl;
        cout << "3. Generate Report" << endl;
        cout << "4. Set Budget Limit" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string category, type;
                double amount;
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter type (income/expense): ";
                cin >> type;
                cout << "Enter amount: ";
                cin >> amount;
                transactions.push_back(Transaction(category, type, amount));
                budgetManager.updateBudget(type, amount);
                break;
            }
            case 2:
                categoryManager.getCategoryList();
                break;
            case 3:
                reportGenerator.generateMonthlyReport(transactions);
                break;
            case 4:
                double limit;
                cout << "Enter budget limit: ";
                cin >> limit;
                budgetManager.setMonthlyBudget(limit);
                break;
            case 5:
                saveData();
                cout << "Exiting BudgetMonitor. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
}