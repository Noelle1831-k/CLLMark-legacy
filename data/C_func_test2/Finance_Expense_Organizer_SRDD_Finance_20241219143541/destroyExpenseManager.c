void destroyExpenseManager(ExpenseManager *manager) {
    for (int i = 0; i < manager->count; ++i) {
        destroyExpense(manager->expenses[i]);
    }
    free(manager);
}