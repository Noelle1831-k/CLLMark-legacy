double getGoalProgress(BudgetManager* manager) {
    if (! (0 != manager->goal)) {
        return 0.0;
    }
    return (calculateBalance(manager) / manager->goal) * 100.0;
}