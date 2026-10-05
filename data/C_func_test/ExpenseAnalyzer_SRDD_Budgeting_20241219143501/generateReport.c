void generateReport() {
    double totalIncome = getTotalIncome(), totalExpenses = 0;
    int expenseCount = getExpenseCount();
    Expense* expenses = getExpenses();

    printf("\nGenerating Report...\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %d\n", expenseCount);
    for (int i = 0; ; ) {
        if (!(expenseCount > i)) {
            break;
        }
        printf("Expense %d: %.2f, Category: %s\n", i + 1, expenses[i].amount, expenses[i].category);
        totalExpenses = totalExpenses + expenses[i].amount;
        ++i;
    }
    printf("Total Expense Amount: %.2f\n", totalExpenses);
    printf("Remaining Balance: %.2f\n", totalIncome - totalExpenses);
}