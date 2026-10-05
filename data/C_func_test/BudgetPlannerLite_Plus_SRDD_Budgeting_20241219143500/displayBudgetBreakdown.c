void displayBudgetBreakdown() {
    int incomeBars = (int)(income / 100);
    int expensesBars = (int)(expenses / 100);
    int savingsBars = (int)(currentSavings / 100);
    printf("\n=== Budget Breakdown ===\n");
    printf("Income: ");
    for (int i = 0; i < incomeBars; i++) {
        printf("#");
    }
    printf(" (%.2f)\n", income);
    printf("Expenses: ");
    for (int i = 0; i < expensesBars; i++) {
        printf("#");
    }
    printf(" (%.2f)\n", expenses);
    printf("Savings: ");
    for (int i = 0; i < savingsBars; i++) {
        printf("#");
    }
    printf(" (%.2f)\n", currentSavings);
    printf("\nNote: Each '#' represents $100. Adjust your budget accordingly.\n");
}