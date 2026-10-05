void BudgetManager::addExpense(double amount, string category) {
    totalExpenses += amount;
    expenses[category] += amount;
    cout << "Expense added successfully.\n";
}