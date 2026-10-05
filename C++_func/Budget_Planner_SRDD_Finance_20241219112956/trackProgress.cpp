void BudgetPlanner::trackProgress() {
    double totalExpenses = 0;
    for (int i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses[i].getAmount();
    }
    double progress = (income - totalExpenses) / savingsGoal * 100;
    cout << "Progress towards savings goal: " << progress << "%" << endl;
}