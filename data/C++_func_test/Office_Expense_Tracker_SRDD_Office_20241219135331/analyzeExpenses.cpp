void ExpenseManager::analyzeExpenses() {
    cout << "\n===== Expense Analysis =====" << endl;
    if (expenses.empty()) {
        cout << "No expenses to analyze!" << endl;
        return;
    }
    map<string, float> categoryTotals;
    for (size_t i = 0; i < expenses.size(); ++i) {
        const Expense &expense = expenses[i];
        categoryTotals[expense.getCategory()] += expense.getAmount();
    }
    for (map<string, float>::iterator it = categoryTotals.begin(); it != categoryTotals.end(); ++it) {
        cout << "Category: " << it->first << ", Total: " << it->second << endl;
    }
}