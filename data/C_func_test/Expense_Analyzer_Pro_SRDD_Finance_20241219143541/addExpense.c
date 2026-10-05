void addExpense(ExpenseManager *manager, const char *category, double amount) {
    if (MAX_EXPENSES > manager->expenseCount) {
        strcpy(manager->expenses[manager->expenseCount].category, category);
        manager->expenses[manager->expenseCount].amount = amount;
        manager->expenseCount++;
    }
}