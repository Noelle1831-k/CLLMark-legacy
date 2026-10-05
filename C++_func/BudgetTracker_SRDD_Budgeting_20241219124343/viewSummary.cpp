void viewSummary() const {
        cout << fixed << setprecision(2);
        cout << "\nBudget Summary:" << endl;
        cout << "Total Income: $" << totalIncome << endl;
        double totalExpenses = 0.0;
        for (const auto& category : categories) {
            cout << category.getName() << ": $" << category.getTotalExpense() << endl;
            totalExpenses += category.getTotalExpense();
        }
        cout << "Total Expenses: $" << totalExpenses << endl;
        cout << "Remaining Balance: $" << (totalIncome - totalExpenses) << endl;
    }