void BudgetAnalyzer::suggestSavings(const vector<Expense>& expenses) const {
    map<string, double> categoryTotals;
    for (size_t i = 0; i < expenses.size(); i++) {
        categoryTotals[expenses[i].getCategory()] += expenses[i].getAmount();
    }
    cout << "Savings Suggestions:" << endl;
    for (const auto& category : categoryTotals) {
        if (category.second > 100) {
            cout << "Consider reducing spending in the category: " << category.first << endl;
        }
    }
    cout << endl;
}