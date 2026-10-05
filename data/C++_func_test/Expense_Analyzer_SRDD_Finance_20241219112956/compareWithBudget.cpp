void ExpenseManager::compareWithBudget(const UserBudget &budget) const {
    map<string, double> totals = calculateCategoryTotals();
    for (map<string, double>::const_iterator it = totals.begin(); it != totals.end(); ++it) {
        double budgetValue = budget.getBudget(it->first);
        cout << "Category: " << it->first << ", Spent: $" << it->second;
        if (0 < budgetValue) {
            cout << ", Budget: $" << budgetValue;
            if (budgetValue < it->second) {
                cout << " (Over Budget)";
            }
        }
        cout << endl;
    }
}