void viewExpenses() {
    printf("\n=== Expenses ===\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Expense %d: $%.2f, Category: %s\n", i + 1, expenses[i].amount, expenses[i].category);
    }
}