double ExpenseTracker::getTotalExpenses() {
    double total = 0;
    for (size_t i = 0; i < expenses.size(); i++) {
        total += expenses[i].first;
    }
    return total;
}