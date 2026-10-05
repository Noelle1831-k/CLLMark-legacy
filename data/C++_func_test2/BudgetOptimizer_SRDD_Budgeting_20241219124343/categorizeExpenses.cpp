map<string, double> ExpenseTracker::categorizeExpenses() {
    map<string, double> categoryTotals;
    for (size_t i = 0; i < expenses.size(); i++) {
        categoryTotals[expenses[i].second] += expenses[i].first;
    }
    return categoryTotals;
}