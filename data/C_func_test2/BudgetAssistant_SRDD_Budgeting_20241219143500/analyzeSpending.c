void analyzeSpending() {
    double totalIncome = 0, totalExpenses = 0;
    for (int i = 0; i < incomeCount; i++) {
        totalIncome += income[i].amount;
    }
    for (int i = 0; i < expenseCount; i++) {
        totalExpenses += expenses[i].amount;
    }
    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    if (totalExpenses > totalIncome) {
        printf("Warning: You are overspending!\n");
    } else {
        printf("Good job! You are within your budget.\n");
    }
    printf("\nBudget Goals Analysis:\n");
    for (int i = 0; i < budgetGoalCount; i++) {
        double categorySpending = 0;
        for (int j = 0; j < expenseCount; j++) {
            if (strcmp(budgetGoals[i].category, expenses[j].category) == 0) {
                categorySpending += expenses[j].amount;
            }
        }
        printf("Category: %s, Target: %.2f, Spent: %.2f\n",
               budgetGoals[i].category, budgetGoals[i].target, categorySpending);
        if (categorySpending > budgetGoals[i].target) {
            printf("  Overspent in %s by %.2f!\n",
                   budgetGoals[i].category, categorySpending - budgetGoals[i].target);
        } else {
            printf("  On track in %s. %.2f left to spend.\n",
                   budgetGoals[i].category, budgetGoals[i].target - categorySpending);
        }
    }
}