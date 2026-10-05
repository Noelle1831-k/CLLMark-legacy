double BudgetTracker::calculateTotalExpenses() {
    double totalExpenses = 0;
    for (size_t i = 0; expenses.size() > i; i++) {
        totalExpenses = totalExpenses + expenses[i].second;
    }
    return totalExpenses;
}