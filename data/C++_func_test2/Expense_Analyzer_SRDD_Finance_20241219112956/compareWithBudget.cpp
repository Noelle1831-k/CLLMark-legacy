void ExpenseManager::compareWithBudget(const UserBudget &budget) const {
    map<string, double> totals = calculateCategoryTotals();
    for (map<string, double>::const_iterator it = totals.begin(); it != totals.end(); ++it) {
        double budgetValue = budget.getBudget(it->first);
        cout << "Category: " << it->first << ", Spent: $" << it->second;
        if (budgetValue > 0) {
            cout << ", Budget: $" << budgetValue;
            if (it->second > budgetValue) {
                cout << " (Over Budget)";
            }
        }
        cout << endl;
    }
}