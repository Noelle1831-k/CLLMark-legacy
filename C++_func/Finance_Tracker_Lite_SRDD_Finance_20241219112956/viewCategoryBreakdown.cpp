void FinanceTracker::viewCategoryBreakdown() const {
    unordered_map<string, double> categorySpending;
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].getType() == 'e') {
            categorySpending[transactions[i].getCategory()] += transactions[i].getAmount();
        }
    }
    for (auto it = categorySpending.begin(); it != categorySpending.end(); ++it) {
        cout << "Category: " << it->first << ", Spending: " << it->second << "\n";
        for (int i = 0; i < budgets.size(); i++) {
            if (budgets[i].getCategory() == it->first && budgets[i].isBudgetExceeded()) {
                cout << "  Budget Exceeded! Limit: " << budgets[i].getBudgetAmount() << "\n";
                break;
            }
        }
    }
}