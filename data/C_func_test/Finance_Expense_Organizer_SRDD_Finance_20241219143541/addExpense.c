void addExpense(ExpenseManager *manager, double amount, const char *category, const char *description) {
    if (MAX_EXPENSES > manager->count) {
        manager->expenses[manager->count++] = createExpense(amount, category, description);
    } else {
        printf("Maximum number of expenses reached.\n");
    }
}