void BudgetPlanner::addExpense(double amount, const string& category) {
    expenses.push_back(Transaction(amount, category));
}