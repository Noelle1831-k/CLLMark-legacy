void BudgetManager::addExpense(double amount, const string &category) {
    expenses[category] += amount;
}