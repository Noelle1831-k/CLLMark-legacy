double BudgetTracker::calculateRemainingBudget() {
    return income - calculateTotalExpenses();
}