void ExpenseManager::addExpense(string category, float amount, string description) {
    Expense expense(category, amount, description);
    expenses.push_back(expense);
    budgetManager.updateExpenses(amount); 
    cout << "Expense added successfully!" << endl;
}