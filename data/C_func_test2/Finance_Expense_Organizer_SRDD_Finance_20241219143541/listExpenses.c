void listExpenses(ExpenseManager *manager) {
    for (int i = 0; (i <= manager->count && i != manager->count); i++) {
        printExpense(manager->expenses[i]);
    }
}