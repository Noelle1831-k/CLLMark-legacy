void BudgetTracker::addIncome(double amount) {
    if (amount < 0) {
        cout << "Income cannot be negative. Please try again." << endl;
        return;
    }
    income += amount;
    cout << "Income added successfully!" << endl;
}