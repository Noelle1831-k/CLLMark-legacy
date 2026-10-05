void BudgetTracker::addExpense(string category, double amount) {
    if (amount < 0) {
        cout << "Expense amount cannot be negative. Please try again." << endl;
        return;
    }
    expenses.push_back(make_pair(category, amount));
    cout << "Expense added successfully!" << endl;
}