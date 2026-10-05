void generateReport() {
    printf("=================================\n");
    printf("         Expense Report\n");
    printf("=================================\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Expense #%d: $%.2f | Category: %s\n", i + 1, expenses[i].amount, expenses[i].category);
    }
    printf("=================================\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", calculateBalance());
    printf("Remaining Balance: $%.2f\n", calculateBalance());
}