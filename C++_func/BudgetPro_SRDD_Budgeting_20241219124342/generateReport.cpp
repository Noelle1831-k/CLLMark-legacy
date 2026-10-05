void BudgetManager::generateReport() const {
    cout << "\nBudget Report:\n";
    cout << "Total Income: $" << totalIncome << "\n";
    cout << "Total Expenses: $" << totalExpenses << "\n";
    cout << "Remaining Budget: $" << totalIncome - totalExpenses << "\n";
    cout << "Transactions:\n";
    for (const auto& transaction : transactions) {
        cout << transaction.getDetails() << "\n";
    }
}