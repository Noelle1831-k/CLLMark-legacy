void visualizeBudget(const Budget b) {
    printf("\n========== Budget Breakdown ==========\n");
    printf("Income: $%.2f\n", b.income);
    printf("Goal: $%.2f\n", b.goal);
    double totalExpenses = calculateTotalExpenses(b);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    if (b.expenseCount > 0) {
        printf("\nExpenses:\n");
        for (int i = 0; i < b.expenseCount; i++) {
            double percentage = (b.expenses[i].amount / totalExpenses) * 100;
            printf("%s: $%.2f (%.2f%%)\n", b.expenses[i].category, b.expenses[i].amount, percentage);
        }
    }
    double remainingBudget = calculateRemainingBudget(b);
    printf("\nRemaining Budget: $%.2f\n", remainingBudget);
    int barLength = 50;
    int remainingBars = (int)((remainingBudget / b.income) * barLength);
    int spentBars = barLength - remainingBars;
    printf("Budget Status: |");
    for (int i = 0; i < spentBars; i++) {
        printf("#");
    }
    for (int i = 0; i < remainingBars; i++) {
        printf("-");
    }
    printf("|\n");
}