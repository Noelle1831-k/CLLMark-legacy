void calculateSavings(double income, double savingsGoal, double expenses[]) {
    if (income <= 0) {
        printf("Error: Monthly income must be greater than 0.\n");
        return;
    }
    double totalExpenses = calculateExpenses(expenses);
    double remainingIncome = income - totalExpenses;
    double optimalSavings = remainingIncome > savingsGoal ? savingsGoal : remainingIncome;
    printLine();
    printf("Savings Plan Summary:\n");
    printLine();
    printf("Total Expenses: %.2lf\n", totalExpenses);
    printf("Remaining Income: %.2lf\n", remainingIncome);
    printf("Optimal Savings: %.2lf\n", optimalSavings);
    if (remainingIncome < savingsGoal) {
        printf("Warning: Your remaining income is less than your savings goal.\n");
    }
}