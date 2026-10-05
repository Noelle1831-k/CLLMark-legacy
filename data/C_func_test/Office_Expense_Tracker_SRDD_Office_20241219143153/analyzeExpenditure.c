void analyzeExpenditure() {
    double totalExpenses = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        totalExpenses += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", totalExpenses);
    if (budget > 0) {
        if (totalExpenses > budget) {
            printf("Warning: You have exceeded your budget by %.2f\n", totalExpenses - budget);
        } else {
            printf("You are within your budget.\n");
        }
    }
    printf("Consider reviewing high-expense categories for potential savings.\n");
}