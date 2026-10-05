void addExpense() {
        string category;
        double amount;
        cout << "Enter expense category: ";
        cin >> category;
        cout << "Enter expense amount: ";
        cin >> amount;
        transactions.push_back(Transaction(0, category, amount));
        totalExpenses += amount;
        cout << "Expense added successfully!\n";
    }