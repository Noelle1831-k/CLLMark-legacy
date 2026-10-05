void addExpense(ExpenseManager* manager, Expense* expense) {
    if (manager->count >= MAX_EXPENSES) {
        printf("Error: Maximum expense capacity reached.\n");
        return;
    }
    manager->expenses[manager->count++] = expense;
}