void BudgetManager::displayBudgetBreakdown() {
    cout << "Income Breakdown:" << endl;
    for (map<string, double>::iterator it = incomeSources.begin(); it != incomeSources.end(); ++it) {
        cout << it->first << ": $" << fixed << setprecision(2) << it->second << endl;
    }
    cout << "Expense Breakdown:" << endl;
    for (map<string, double>::iterator it = expenseCategories.begin(); it != expenseCategories.end(); ++it) {
        cout << it->first << ": $" << fixed << setprecision(2) << it->second << endl;
    }
}