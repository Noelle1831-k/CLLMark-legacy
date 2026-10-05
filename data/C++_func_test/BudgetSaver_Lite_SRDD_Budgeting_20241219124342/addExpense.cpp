void BudgetManager::addExpense(double amount, const string& category) {
    if (amount <= 0) {
        throw invalid_argument("Expense amount must be positive.");
    }
    totalExpenses += amount;
    expenseCategories[category] += amount;
}