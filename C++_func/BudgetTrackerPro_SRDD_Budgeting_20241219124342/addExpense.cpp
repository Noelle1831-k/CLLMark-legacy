void BudgetTracker::addExpense(double amount, const string& category) {
    expenses.push_back(make_pair(amount, category));
    cout << "Expense added successfully!" << endl;
}