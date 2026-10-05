void BudgetPlanner::calculateRecommendations() {
    double totalExpenses = 0;
    for (int i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses[i].getAmount();
    }
    double remaining = income - totalExpenses;
    cout << "Remaining budget: " << remaining << endl;
    cout << "Savings goal: " << savingsGoal << endl;
}