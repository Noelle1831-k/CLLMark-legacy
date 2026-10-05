void BudgetManager::generateReport() const {
    cout << "\nBudget Report:" << endl;
    cout << "Total Income: $" << fixed << setprecision(2) << totalIncome << endl;
    cout << "Total Expenses: $" << fixed << setprecision(2) << totalExpenses << endl;
    cout << "Remaining Budget: $" << fixed << setprecision(2) << calculateRemainingBudget() << endl;
}