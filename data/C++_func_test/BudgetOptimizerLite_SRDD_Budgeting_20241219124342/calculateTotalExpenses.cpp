double BudgetManager::calculateTotalExpenses() const {
    double total = 0;
    for (const auto &pair : expenses) {
        total += pair.second;
    }
    return total;
}