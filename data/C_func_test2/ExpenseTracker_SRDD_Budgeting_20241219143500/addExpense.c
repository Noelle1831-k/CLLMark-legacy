void addExpense(ExpenseManager *manager, const char *description, double amount) {
    if (manager->count == manager->capacity) {
        manager->capacity *= 2;
        manager->expenses = (Expense *)realloc(manager->expenses, sizeof(Expense) * manager->capacity);
    }
    strcpy(manager->expenses[manager->count].description, description);
    manager->expenses[manager->count].amount = amount;
    manager->count++;
}