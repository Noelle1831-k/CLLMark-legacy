void BudgetManager::addIncome(double amount, const string &description) {
    if (amount > 0) {
        incomes.emplace_back(amount, description);
        cout << "Income added successfully!\n";
    } else {
        cout << "Invalid income amount.\n";
    }
}