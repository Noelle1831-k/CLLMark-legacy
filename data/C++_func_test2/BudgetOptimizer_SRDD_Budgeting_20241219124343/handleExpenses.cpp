void handleExpenses() {
        double amount;
        string category;
        cout << "Enter expense amount: ";
        cin >> amount;
        cout << "Enter expense category: ";
        cin.ignore();
        getline(cin, category);
        expenseTracker.addExpense(amount, category);
        cout << "Expense added successfully.\n";
    }