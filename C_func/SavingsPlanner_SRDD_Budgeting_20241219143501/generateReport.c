void generateReport() {
    printf("\n== Savings Report ==\n");
    printf("Total Income: %.2f\n", budget.income);
    printf("Total Expenses: %.2f\n", budget.expenses);
    printf("Current Savings: %.2f\n", budget.currentSavings);
    printf("Savings Target: %.2f\n", budget.savingsTarget);
}