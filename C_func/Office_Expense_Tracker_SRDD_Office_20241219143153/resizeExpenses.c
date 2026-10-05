void resizeExpenses() {
    expenseCapacity *= 2;
    expenses = (Expense *)realloc(expenses, expenseCapacity * sizeof(Expense));
    if (!expenses) {
        printf("Memory reallocation failed for expenses.\n");
        exit(EXIT_FAILURE);
    }
}