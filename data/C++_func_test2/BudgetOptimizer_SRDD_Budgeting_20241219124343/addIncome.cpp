void IncomeTracker::addIncome(double amount, string source) {
    incomes.push_back(make_pair(amount, source));
}