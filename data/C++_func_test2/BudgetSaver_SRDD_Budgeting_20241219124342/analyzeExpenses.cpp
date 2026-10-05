void BudgetAnalyzer::analyzeExpenses(const vector<Expense>& expenses) const {
    map<string, double> categoryTotals;
    for (size_t i = 0; i < expenses.size(); i++) {
        categoryTotals[expenses[i].getCategory()] += expenses[i].getAmount();
    }
    cout << "Expense Analysis by Category:" << endl;
    cout << left << setw(20) << "Category" << setw(10) << "Amount" << endl;
    cout << string(30, '-') << endl;
    for (const auto& category : categoryTotals) {
        cout << left << setw(20) << category.first << "$" << setw(10) << fixed << setprecision(2) << category.second << endl;
    }
    cout << endl;
}