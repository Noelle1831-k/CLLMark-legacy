void showBudgetBreakdown(BudgetManager *budgetManager, GoalManager *goalManager, SavingsTracker *savingsTracker) {
    printf("\n--- Budget Breakdown ---\n");
    printf("Total Income: %.2lf\n", budgetManager->income);
    printf("Total Expenses: %.2lf\n", budgetManager->expenses);
    printf("Current Balance: %.2lf\n", budgetManager->income - budgetManager->expenses);
    printf("Goal Progress: %.2lf/%.2lf\n", goalManager->currentProgress, goalManager->goalAmount);
    printf("Savings Progress: %.2lf/%.2lf\n", savingsTracker->currentSavings, savingsTracker->savingsGoal);
    printf("-------------------------\n");
}