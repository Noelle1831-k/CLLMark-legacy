void FinanceTracker::addTransaction(double amount, string description, string category, char type) {
    Transaction transaction(amount, description, category, type);
    transactions.push_back(transaction);
    if (type == 'e') {
        for (int i = 0; i < budgets.size(); i++) {
            if (budgets[i].getCategory() == category) {
                budgets[i].setCurrentSpending(budgets[i].getCurrentSpending() + amount);
                break;
            }
        }
    }
}