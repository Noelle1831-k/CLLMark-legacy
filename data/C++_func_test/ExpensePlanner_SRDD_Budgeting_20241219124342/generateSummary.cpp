void Visualization::generateSummary(const vector<Expense>& expenses) const {
    map<string, double> categoryTotals;
    for (const auto& expense : expenses) {
        categoryTotals[expense.getCategory()] += expense.getAmount();
    }
    cout << "Expense Summary by Category:\n";
    for (const auto& pair : categoryTotals) {
        cout << pair.first << ": $" << pair.second << endl;
    }
}