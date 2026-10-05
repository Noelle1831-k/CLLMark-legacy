void allocateExpenses() {
    double income, savingsGoal, totalExpenses = 0.0;
    int categories;
    printf("Enter your monthly income: ");
    income = getValidatedDouble();
    printf("Enter your savings goal: ");
    savingsGoal = getValidatedDouble();
    printf("Enter the number of expense categories: ");
    categories = getValidatedInteger();
    double *expenses = (double *)malloc(categories * sizeof(double));
    if (!expenses) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i < categories; i++) {
        printf("Enter expense for category %d: ", i + 1);
        expenses[i] = getValidatedDouble();
        totalExpenses += expenses[i];
    }
    if (totalExpenses + savingsGoal > income) {
        printf("Warning: Your expenses exceed your income after savings!\n");
    } else {
        printf("Expenses allocated successfully.\n");
    }
    printf("\nDetailed Expense Allocation:\n");
    for (int i = 0; i < categories; i++) {
        printf("Category %d: $%.2f\n", i + 1, expenses[i]);
    }
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Savings Goal: $%.2f\n", savingsGoal);
    printf("Remaining Income: $%.2f\n", income - totalExpenses - savingsGoal);
    free(expenses);
}