void allocateIncome(double income, double expenses[]) {
    if (income <= 0) {
        printf("Error: Monthly income must be greater than 0.\n");
        return;
    }
    double totalExpenses = calculateExpenses(expenses);
    double remainingIncome = income - totalExpenses;
    printLine();
    printf("Income Allocation:\n");
    printLine();
    printf("Food: %.2lf\n", expenses[0]);
    printf("Transportation: %.2lf\n", expenses[1]);
    printf("Rent: %.2lf\n", expenses[2]);
    printf("Utilities: %.2lf\n", expenses[3]);
    printf("Others: %.2lf\n", expenses[4]);
    printf("Remaining Income: %.2lf\n", remainingIncome);
    if (remainingIncome < 0) {
        printf("Warning: Your expenses exceed your income. Consider reducing your expenses.\n");
    }
}