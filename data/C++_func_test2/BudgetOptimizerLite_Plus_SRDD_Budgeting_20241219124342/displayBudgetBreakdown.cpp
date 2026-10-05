void BudgetManager::displayBudgetBreakdown() {
    cout << fixed << setprecision(2);
    cout << "-----------------------------------------" << endl;
    cout << "Budget Breakdown:" << endl;
    cout << "Total Income: $" << totalIncome << endl;
    cout << "Total Expenses: $" << totalExpenses << endl;
    cout << "Remaining Budget: $" << (totalIncome - totalExpenses) << endl;
    cout << "Expenses by Category:" << endl;
    for (map<string, double>::iterator it = expenseCategories.begin(); it != expenseCategories.end(); ++it) {
        cout << "  " << it->first << ": $" << it->second << endl;
    }
    cout << "-----------------------------------------" << endl;
}