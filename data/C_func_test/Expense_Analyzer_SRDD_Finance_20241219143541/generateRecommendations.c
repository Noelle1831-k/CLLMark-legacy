void generateRecommendations(RecommendationEngine *engine, ExpenseManager *expenseManager, BudgetManager *budgetManager) {
    printf("Recommendations:\n");
    for (int i = 0; i < expenseManager->expenseCount; i++) {
        double remainingBudget = compareWithBudget(budgetManager, expenseManager->expenses[i].category, expenseManager->expenses[i].amount);
        if (remainingBudget < 0) {
            printf("You have exceeded your budget for %s by %.2f. Consider reducing expenses in this category.\n", expenseManager->expenses[i].category, -remainingBudget);
        }
    }
}