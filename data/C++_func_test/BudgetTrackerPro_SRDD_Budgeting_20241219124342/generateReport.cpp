void BudgetTracker::generateReport() {
    cout << "==================== Budget Report ====================" << endl;
    cout << "Income:" << endl;
    for (size_t i = 0; i < income.size(); i++) {
        cout << "- $" << fixed << setprecision(2) << income[i].first << " (" << income[i].second << ")" << endl;
    }
    cout << "Expenses:" << endl;
    for (size_t i = 0; i < expenses.size(); i++) {
        cout << "- $" << fixed << setprecision(2) << expenses[i].first << " (" << expenses[i].second << ")" << endl;
    }
    calculateBudget();
    cout << "======================================================" << endl;
}