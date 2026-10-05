void ExpenseManager::addExpense(const Expense& exp) {
    expenses.push_back(exp);
    cout << "Expense added successfully!\n";
}