bool BudgetManager::checkBudgetGoal() {
    return (totalIncome - totalExpenses) >= budgetGoal;
}