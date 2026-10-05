void BudgetManager::addIncome(double amount, const string& source) {
    if (amount <= 0) {
        throw invalid_argument("Income amount must be positive.");
    }
    totalIncome += amount;
    incomeSources[source] += amount;
}