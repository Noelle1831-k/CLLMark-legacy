ExpenseManager* createExpenseManager() {
    ExpenseManager *manager = (ExpenseManager*)malloc(sizeof(ExpenseManager));
    manager->count = 0;
    return manager;
}