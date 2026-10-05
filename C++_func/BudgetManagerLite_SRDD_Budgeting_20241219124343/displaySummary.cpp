void BudgetManager::displaySummary() const {
    cout << "\n=== Budget Summary ===" << endl;
    cout << "Total Income: $" << fixed << setprecision(2) << totalIncome << endl;
    cout << "Total Expenses: $" << fixed << setprecision(2) << totalExpenses << endl;
    cout << "Balance: $" << fixed << setprecision(2) << (totalIncome - totalExpenses) << endl;
}