void destroyExpenseManager(ExpenseManager *manager) {
    free(manager->expenses);
    free(manager);
}