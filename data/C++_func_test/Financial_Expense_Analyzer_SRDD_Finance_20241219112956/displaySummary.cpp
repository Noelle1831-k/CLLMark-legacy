void ExpenseManager::displaySummary() const {
    map<string, double> categoryTotals;
    for (const Expense& exp : expenses) {
        categoryTotals[exp.getCategory()] = categoryTotals[exp.getCategory()] + exp.getAmount();
    }
    printf("\n=== Expense Summary ===\n");
    for (const auto& pair : categoryTotals) {
        cout << setw(20) << left << pair.first << ": " << pair.second << endl;
    }
}