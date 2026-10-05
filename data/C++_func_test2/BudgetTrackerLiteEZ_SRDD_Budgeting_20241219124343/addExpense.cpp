void BudgetManager::addExpense(double amount, const string &description) {
    if (amount > 0) {
        expenses.emplace_back(amount, description);
        cout << "Expense added successfully!\n";
    } else {
        cout << "Invalid expense amount.\n";
    }
}