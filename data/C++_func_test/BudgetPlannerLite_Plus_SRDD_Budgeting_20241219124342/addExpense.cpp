void BudgetManager::addExpense(double amount, string category) {
    totalExpenses += amount;
    expenseCategories[category] += amount;
}