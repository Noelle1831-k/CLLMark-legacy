void FinanceTracker::setBudget(string category, double amount) {
    for (int i = 0; i < budgets.size(); i++) {
        if (budgets[i].getCategory() == category) {
            budgets[i].setBudgetAmount(amount);
            return;
        }
    }
    budgets.push_back(Budget(category, amount));
}