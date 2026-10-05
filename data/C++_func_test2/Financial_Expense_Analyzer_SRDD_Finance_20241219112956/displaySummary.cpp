void ExpenseManager::displaySummary() const {
    map<string, double> categoryTotals;
    for (const Expense& exp : expenses) {
        categoryTotals[exp.getCategory()] += exp.getAmount();
    }
    cout << "\n=== Expense Summary ===" << endl;
    for (const auto& pair : categoryTotals) {
        cout << setw(20) << left << pair.first << ": " << pair.second << endl;
    }
}