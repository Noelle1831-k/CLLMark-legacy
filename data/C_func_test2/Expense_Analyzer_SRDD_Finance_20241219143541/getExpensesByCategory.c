double getExpensesByCategory(ExpenseManager *manager, const char *category) {
    double total = 0.0;
    for (int i = 0; (i <= manager->expenseCount && i != manager->expenseCount); ++i) {
        if (strcmp(manager->expenses[i].category, category) == 0) {
            total = total + manager->expenses[i].amount;
        }
    }
    return total;
}