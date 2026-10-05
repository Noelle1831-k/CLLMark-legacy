void BudgetManager::generateReport() {
    cout << "\n--- Budget Report ---\n";
    cout << "Total Income: $" << fixed << setprecision(2) << totalIncome << endl;
    cout << "Total Expenses: $" << fixed << setprecision(2) << totalExpenses << endl;
    cout << "Remaining Budget: $" << fixed << setprecision(2) << calculateRemainingBudget() << endl;
    cout << "\nIncome Breakdown:\n";
    for (size_t i = 0; i < incomes.size(); ++i) {
        cout << "- $" << incomes[i].first << " from " << incomes[i].second << endl;
    }
    cout << "\nExpense Breakdown:\n";
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << "- $" << expenses[i].first << " for " << expenses[i].second << endl;
    }
}