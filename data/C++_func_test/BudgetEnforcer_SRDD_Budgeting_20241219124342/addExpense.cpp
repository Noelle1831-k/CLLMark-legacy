void BudgetManager::addExpense(double amount, string category) {
    if (expenses.find(category) == expenses.end()) {
        expenses[category] = 0.0;
    }
    expenses[category] += amount;
    totalBudget -= amount;
}