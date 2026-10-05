void BudgetManager::addIncome(double amount, string source) {
    totalIncome += amount;
    incomeSources[source] += amount;
}