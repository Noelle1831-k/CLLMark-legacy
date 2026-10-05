void generateReport() {
    double totalIncome = getTotalIncome();
    int expenseCount = getExpenseCount();
    Expense* expenses = getExpenses();
    double totalExpenses = 0;
    printf("\nGenerating Report...\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %d\n", expenseCount);
    for (int i = 0; i < expenseCount; i++) {
        printf("Expense %d: %.2f, Category: %s\n", i + 1, expenses[i].amount, expenses[i].category);
        totalExpenses += expenses[i].amount;
    }
    printf("Total Expense Amount: %.2f\n", totalExpenses);
    printf("Remaining Balance: %.2f\n", totalIncome - totalExpenses);
}