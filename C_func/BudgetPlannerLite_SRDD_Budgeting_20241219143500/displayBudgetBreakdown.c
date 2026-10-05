void displayBudgetBreakdown() {
    double totalIncome = calculateTotalIncome();
    double totalExpenses = calculateTotalExpenses();
    if (totalIncome == 0) {
        printf("No income data available to display breakdown.\n");
        return;
    }
    double expensePercentage = (totalExpenses / totalIncome) * 100;
    double savingsPercentage = 100 - expensePercentage;
    printf("\nBudget Breakdown:\n");
    printf("Expenses: %.2f%%\n", expensePercentage);
    printf("Savings: %.2f%%\n", savingsPercentage);
}