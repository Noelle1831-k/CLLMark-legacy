void Report::generateCategoryBreakdown() const {
    map<string, double> categoryTotals;
    for (const auto &transaction : transactions) {
        categoryTotals[transaction.getCategory()] = categoryTotals[transaction.getCategory()] + transaction.getAmount();
    }
    printf("\n=== Category Breakdown ===\n");
    for (const auto &entry : categoryTotals) {
        cout << "Category: " << entry.first << " | Total: $" << fixed << setprecision(2) << entry.second << endl;
    }
}