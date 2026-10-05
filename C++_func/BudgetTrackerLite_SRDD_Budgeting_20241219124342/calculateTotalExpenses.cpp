double BudgetTracker::calculateTotalExpenses() {
    double totalExpenses = 0;
    for (size_t i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses[i].second;
    }
    return totalExpenses;
}