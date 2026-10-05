ExpenseManager* createExpenseManager() {
    ExpenseManager *manager = (ExpenseManager *)malloc(sizeof(ExpenseManager));
    manager->expenses = (Expense *)malloc(sizeof(Expense) * 10);
    manager->count = 0;
    manager->capacity = 10;
    return manager;
}