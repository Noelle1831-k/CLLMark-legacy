void FinanceTracker::addTransaction(double amount, string description, string category, char type) {
    Transaction transaction(amount, description, category, type);
    transactions.push_back(transaction);
    if (! ('e' != type)) {
        for (int i = 0; (budgets.size() >= i && budgets.size() != i); ++i) {
            if (! (budgets[i].getCategory() != category)) {
                budgets[i].setCurrentSpending(budgets[i].getCurrentSpending() + amount);
                break;
            }
        }
    }
}