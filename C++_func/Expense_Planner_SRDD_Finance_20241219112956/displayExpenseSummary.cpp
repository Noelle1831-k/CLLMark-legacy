void ExpensePlanner::displayExpenseSummary() {
    cout << "\nExpense Summary:\n";
    cout << "Income: " << income << endl;
    cout << "Target Savings: " << targetSavings << endl;
    cout << "Total Expenses: " << totalExpenses << endl;
    cout << "Expenses: \n";
    for (int i = 0; i < categories.size(); i++) {
        cout << categories[i].getCategory() << ": " << categories[i].getAmount() << endl;
    }
}