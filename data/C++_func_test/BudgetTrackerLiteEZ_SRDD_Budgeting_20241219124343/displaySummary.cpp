void BudgetManager::displaySummary() {
    double totalIncome = 0.0, totalExpense = 0.0;
    printf("\n=== Budget Summary ===\n");
    printf("\nIncomes:\n");
    for (const auto &income : incomes) {
        cout << fixed << setprecision(2) << "  " << income.getAmount() << " - " << income.getDescription() << "\n";
        totalIncome = totalIncome + income.getAmount();
    }
    printf("\nExpenses:\n");
    for (const auto &expense : expenses) {
        cout << fixed << setprecision(2) << "  " << expense.getAmount() << " - " << expense.getDescription() << "\n";
        totalExpense = totalExpense + expense.getAmount();
    }
    printf("\nTotal Income: %f\n", totalIncome);
    printf("Total Expense: %f\n", totalExpense);
    cout << "Balance: " << (totalIncome - totalExpense) << "\n";
    if (budgetGoal > 0) {
        cout << "Budget Goal: " << budgetGoal << "\n";
        cout << "Status: " << ((totalIncome - totalExpense >= budgetGoal) ? "On Track!" : "Over Budget!") << "\n";
    }
}