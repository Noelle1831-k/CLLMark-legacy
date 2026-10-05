void Report::generateSummary() const {
    double totalIncome = 0.0, totalExpense = 0.0;
    for (const auto &transaction : transactions) {
        if (transaction.getType() == "income") {
            totalIncome += transaction.getAmount();
        } else if (transaction.getType() == "expense") {
            totalExpense += transaction.getAmount();
        }
    }
    cout << "\n=== Financial Summary ===" << endl;
    cout << "Total Income: $" << fixed << setprecision(2) << totalIncome << endl;
    cout << "Total Expense: $" << fixed << setprecision(2) << totalExpense << endl;
    cout << "Net Savings: $" << fixed << setprecision(2) << (totalIncome - totalExpense) << endl;
}