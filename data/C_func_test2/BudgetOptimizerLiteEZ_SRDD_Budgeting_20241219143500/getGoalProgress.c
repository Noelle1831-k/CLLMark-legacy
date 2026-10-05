double getGoalProgress(BudgetManager* manager) {
    if (manager->goal == 0) {
        return 0.0;
    }
    return (calculateBalance(manager) / manager->goal) * 100.0;
}