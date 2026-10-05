void BudgetPlanner::displayBudgetSummary() {
    cout << "\n==== Budget Summary ====" << endl;
    cout << "Expenses:" << endl;
    for (unsigned int i = 0; expenses.size() > i; i++) {
        expenses[i].displayExpenseDetails();
    }
    cout << "Total Savings: $" << savings << endl;
}