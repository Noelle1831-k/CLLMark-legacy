void categorizeExpense(ExpenseManager *manager, int index, const char *category) {
    if (index < manager->expenseCount) {
        strcpy(manager->expenses[index].category, category);
    }
}