vector<Expense> ExpenseManager::getExpensesByCategory(const string& category) const {
    vector<Expense> filteredExpenses;
    for (size_t i = 0; i < expenses.size(); i++) {
        if (category.empty() || expenses[i].getCategory() == category) {
            filteredExpenses.push_back(expenses[i]);
        }
    }
    return filteredExpenses;
}