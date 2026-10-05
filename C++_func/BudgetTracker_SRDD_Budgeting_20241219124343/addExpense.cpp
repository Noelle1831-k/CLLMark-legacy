void addExpense(const string& description, double amount) {
        if (amount <= 0) {
            cerr << "Error: Expense amount must be positive." << endl;
            return;
        }
        transactions.push_back({description, amount});
        totalExpense += amount;
    }