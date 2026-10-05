void initializeExpenses() {
    expenses = (Expense *)malloc(expenseCapacity * sizeof(Expense));
    if (!expenses) {
        printf("Memory allocation failed for expenses.\n");
        exit(EXIT_FAILURE);
    }
}