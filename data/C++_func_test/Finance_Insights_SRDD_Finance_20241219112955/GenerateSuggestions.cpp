void FinanceAnalyzer::GenerateSuggestions(const User& user) const {
    double savings = CalculateSavings(user);
    if (savings < 0) {
        cout << "You are spending more than your income. Consider reducing expenses." << endl;
    } else if (savings < user.GetTotalIncome() * 0.2) {
        cout << "Your savings are below 20% of your income. Try to save more." << endl;
    } else {
        cout << "Great job! Your savings are healthy." << endl;
    }
}