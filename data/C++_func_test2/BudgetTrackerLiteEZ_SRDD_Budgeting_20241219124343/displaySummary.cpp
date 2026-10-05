void BudgetManager::displaySummary() {
    double totalIncome = 0.0, totalExpense = 0.0;
    cout << "\n=== Budget Summary ===\n";
    cout << "\nIncomes:\n";
    for (const auto &income : incomes) {
        cout << fixed << setprecision(2) << "  " << income.getAmount() << " - " << income.getDescription() << "\n";
        totalIncome += income.getAmount();
    }
    cout << "\nExpenses:\n";
    for (const auto &expense : expenses) {
        cout << fixed << setprecision(2) << "  " << expense.getAmount() << " - " << expense.getDescription() << "\n";
        totalExpense += expense.getAmount();
    }
    cout << "\nTotal Income: " << totalIncome << "\n";
    cout << "Total Expense: " << totalExpense << "\n";
    cout << "Balance: " << (totalIncome - totalExpense) << "\n";
    if (budgetGoal > 0) {
        cout << "Budget Goal: " << budgetGoal << "\n";
        cout << "Status: " << ((totalIncome - totalExpense >= budgetGoal) ? "On Track!" : "Over Budget!") << "\n";
    }
}