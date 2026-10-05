void list_expenses() {
    printf("\n---- List of Expenses ----\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Category: %s, Amount: %.2f\n", expenses[i].category, expenses[i].amount);
    }
}