void Report::generateCategoryBreakdown() const {
    map<string, double> categoryTotals;
    for (const auto &transaction : transactions) {
        categoryTotals[transaction.getCategory()] += transaction.getAmount();
    }
    cout << "\n=== Category Breakdown ===" << endl;
    for (const auto &entry : categoryTotals) {
        cout << "Category: " << entry.first << " | Total: $" << fixed << setprecision(2) << entry.second << endl;
    }
}