void list_expenses() {
    printf("\nListing all expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Expense %d: %s\n", i + 1, expenses[i].name);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %s\n", expenses[i].date);
        printf("Category: %s\n", expenses[i].category);
        printf("--------------------------\n");
    }
}