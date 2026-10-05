void BudgetTracker::calculateBudget() {
    double totalIncome = 0.0, totalExpenses = 0.0;
    for (size_t i = 0; i < income.size(); i++) {
        totalIncome += income[i].first;
    }
    for (size_t i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses[i].first;
    }
    double remainingBudget = totalIncome - totalExpenses;
    cout << "Remaining Budget: $" << fixed << setprecision(2) << remainingBudget << endl;
}