double FinanceAnalyzer::CalculateSavings(const User& user) const {
    return user.GetTotalIncome() - GetTotalExpenses(user);
}