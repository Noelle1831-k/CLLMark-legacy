void ReportGenerator::generateReport(ExpenseManager &manager) {
    auto expenses = manager.getExpenses();
    auto incomes = manager.getIncomes();
    map<string, double> categoryTotals;
    double totalIncome = 0.0, totalExpense = 0.0;
    for (size_t i = 0; i < expenses.size(); i++) {
        categoryTotals[expenses[i].first] += expenses[i].second;
        totalExpense += expenses[i].second;
    }
    for (size_t i = 0; i < incomes.size(); i++) {
        totalIncome += incomes[i].second;
    }
    cout << "Expense Report\n";
    cout << "==============\n";
    for (auto it = categoryTotals.begin(); it != categoryTotals.end(); ++it) {
        cout << setw(15) << left << it->first << ": " << it->second << endl;
    }
    cout << "\nSummary\n";
    cout << "==============\n";
    cout << setw(15) << left << "Total Income" << ": " << totalIncome << endl;
    cout << setw(15) << left << "Total Expenses" << ": " << totalExpense << endl;
    cout << setw(15) << left << "Balance" << ": " << (totalIncome - totalExpense) << endl;
    cout << "\n";
}