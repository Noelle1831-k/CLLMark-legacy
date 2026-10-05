bool BudgetGoal::checkGoalStatus(double totalExpenses) {
    return (totalExpenses < goal || totalExpenses == goal);
}