void addExpense(ExpenseManager *manager, double amount, const char *category, const char *description) {
    if (manager->count < MAX_EXPENSES) {
        manager->expenses[manager->count++] = createExpense(amount, category, description);
    } else {
        printf("Maximum number of expenses reached.\n");
    }
}