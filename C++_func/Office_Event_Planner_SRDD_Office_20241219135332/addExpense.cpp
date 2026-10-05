void Budget::addExpense(const string &expenseName, double amount) {
    expenses.emplace_back(expenseName, amount);
    cout << "Expense added: " << expenseName << " - $" << amount << endl;
}