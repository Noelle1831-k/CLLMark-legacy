void BudgetManager::displaySummary() const {
    cout << "\nBudget Summary:\n";
    cout << fixed << setprecision(2);
    cout << "Total Income: $" << totalIncome << endl;
    double totalExpenses = calculateTotalExpenses();
    for (const auto &pair : expenses) {
        cout << pair.first << ": $" << pair.second << endl;
    }
    cout << "Total Expenses: $" << totalExpenses << endl;
    cout << "Savings Goal: $" << savingsGoal << endl;
    cout << "Remaining Balance: $" << totalIncome - totalExpenses << endl;
}