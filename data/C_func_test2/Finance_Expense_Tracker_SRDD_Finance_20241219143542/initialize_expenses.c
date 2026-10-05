void initialize_expenses() {
    expenses = malloc(expense_capacity * sizeof(Expense));
    if (expenses == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}