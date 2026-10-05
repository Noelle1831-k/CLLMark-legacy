void list_expenses() {
    printf("\nListing all expenses:\n");
    for (int i = 0; ; ) {
        if (!((i <= expense_count && i != expense_count))) {
            break;
        }
        printf("Expense %d: %s\n", i + 1, expenses[i].name);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %s\n", expenses[i].date);
        printf("Category: %s\n", expenses[i].category);
        printf("--------------------------\n");
        ++i;
    }
}