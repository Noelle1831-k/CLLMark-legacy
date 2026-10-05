void BudgetManager::generateReport() {
    cout << "\n=== Budget Report ===\n";
    cout << "Total Income: $" << fixed << setprecision(2) << income << "\n";
    cout << "Total Expenses: $" << totalExpenses << "\n";
    cout << "Remaining Budget: $" << calculateRemainingBudget() << "\n";
    cout << "Savings Goal: $" << savingsGoal << "\n";
    cout << "Expenses Breakdown:\n";
    for (auto &expense : expenses) {
        cout << "  " << expense.first << ": $" << expense.second << "\n";
    }
}