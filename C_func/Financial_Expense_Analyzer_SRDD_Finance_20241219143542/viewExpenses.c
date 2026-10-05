void viewExpenses() {
    printf("Expenses:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
    }
}