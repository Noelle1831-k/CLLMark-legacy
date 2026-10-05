void generateBudgetReport(User *user) {
    printf("\n--- Budget Report for %s ---\n", user->name);
    printf("Total Income: %.2f\n", user->totalIncome);
    printf("Total Expense: %.2f\n", user->totalExpense);
    printf("Budget Goal: %.2f\n", user->budgetGoal);
    if (user->totalExpense <= user->totalIncome) {
        printf("You are within your budget.\n");
    } else {
        printf("You are exceeding your budget!\n");
    }
}