void BudgetTracker::addIncome(double amount, const string& source) {
    income.push_back(make_pair(amount, source));
    cout << "Income added successfully!" << endl;
}