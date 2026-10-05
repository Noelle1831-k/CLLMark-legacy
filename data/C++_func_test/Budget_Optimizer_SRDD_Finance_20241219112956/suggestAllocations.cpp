void suggestAllocations(User& user) {
        double income = user.getIncome();
        vector<ExpenseCategory> expenses = user.getExpenses();
        double totalExpenses = 0;
        for (int i = 0; i < expenses.size(); i++) {
            totalExpenses = totalExpenses + expenses[i].getTotalAmount();
        }
        double savings = income - totalExpenses;
        cout << "You can save: $" << savings << " this month." << endl;
    }