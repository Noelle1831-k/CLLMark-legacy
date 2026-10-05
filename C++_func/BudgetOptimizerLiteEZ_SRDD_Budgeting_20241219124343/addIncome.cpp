void BudgetManager::addIncome(double amount, string source) {
    totalIncome += amount;
    incomes.push_back(make_pair(amount, source));
}