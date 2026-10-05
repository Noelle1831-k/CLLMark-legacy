void displayBudgetGoals() {
    if (budgetGoalCount == 0) {
        printf("No budget goals have been set.\n");
        return;
    }
    printf("\nYour Budget Goals:\n");
    for (int i = 0; i < budgetGoalCount; i++) {
        printf("Category: %s, Target: %.2f\n", budgetGoals[i].category, budgetGoals[i].target);
    }
}