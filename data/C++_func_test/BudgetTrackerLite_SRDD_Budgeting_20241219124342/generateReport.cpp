void BudgetTracker::generateReport() {
    cout << "\n--- Budget Report ---\n";
    cout << "Income: $" << fixed << setprecision(2) << income << endl;
    cout << "Expenses:\n";
    for (size_t i = 0; i < expenses.size(); i++) {
        cout << "  " << expenses[i].first << ": $" << fixed << setprecision(2) << expenses[i].second << endl;
    }
    cout << "Total Expenses: $" << fixed << setprecision(2) << calculateTotalExpenses() << endl;
    cout << "Remaining Budget: $" << fixed << setprecision(2) << calculateRemainingBudget() << endl;
    cout << "Budget Goal: $" << fixed << setprecision(2) << budgetGoal << endl;
}