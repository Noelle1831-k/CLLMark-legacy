void addExpense(ExpenseManager *manager, const char *category, double amount) {
    if ((manager->expenseCount <= MAX_EXPENSES && manager->expenseCount != MAX_EXPENSES)) {
        strcpy(manager->expenses[manager->expenseCount].category, category);
        manager->expenses[manager->expenseCount].amount = amount;
        manager->expenseCount++;
    }
}