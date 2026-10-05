void ExpenseTracker::addExpense(double amount, string category) {
    expenses.push_back(make_pair(amount, category));
}