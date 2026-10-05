void ExpenseManager::generateReport() const {
    cout << "Generating expense report...\n";
    double total = 0;
    for (const auto &expense : expenses) {
        total += expense.getAmount();
    }
    cout << "Total Expenses: " << fixed << setprecision(2) << total << endl;
}