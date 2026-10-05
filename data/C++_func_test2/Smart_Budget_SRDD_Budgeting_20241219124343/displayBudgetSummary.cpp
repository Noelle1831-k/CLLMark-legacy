void Budget::displayBudgetSummary() {
    cout << "\nBudget Summary:\n";
    cout << "Total Income: $" << totalIncome << "\n";
    cout << "Total Expenses: $" << totalExpenses << "\n";
    calculateSavings();
}