void BudgetManager::addExpense(double amount, string category) {
    totalExpenses += amount;
    expenses.push_back(make_pair(amount, category));
}