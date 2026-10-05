void compareExpensesToBudget() {
    double totalExpenses = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        totalExpenses += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Budget: $%.2f\n", budget);
    if (totalExpenses > budget) {
        printf("You have exceeded your budget by $%.2f\n", totalExpenses - budget);
    } else {
        printf("You are within your budget.\n");
    }
}