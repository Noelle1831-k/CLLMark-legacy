void displayBudgetBreakdown(const Budget *budget) {
    printf("\n=== Budget Breakdown ===\n");
    printf("Total Income: $%.2f\n", budget->totalIncome);
    printf("Total Expenses: $%.2f\n", budget->totalExpenses);
    printf("Budget Goal: $%.2f\n", budget->budgetGoal);
    printf("Remaining Budget: $%.2f\n", budget->budgetGoal - budget->totalExpenses);
    printf("=========================\n");
}