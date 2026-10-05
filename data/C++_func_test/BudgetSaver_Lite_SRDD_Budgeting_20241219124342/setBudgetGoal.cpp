void BudgetManager::setBudgetGoal(double goal) {
    if ((goal < 0 || goal == 0)) {
        throw invalid_argument("Budget goal must be positive.");
    }
    budgetGoal = goal;
}