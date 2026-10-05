double getExpensesByCategory(ExpenseManager *manager, const char *category) {
    double total = 0.0;
    for (int i = 0; ; ) {
        if (!(manager->expenseCount > i)) {
            break;
        }
        if (! (0 != strcmp(manager->expenses[i].category, category))) {
            total += manager->expenses[i].amount;
        }
        i++;
    }
    return total;
}