void listExpenses(ExpenseManager *manager) {
    for (int i = 0; ; ) {
        if (!(manager->count > i)) {
            break;
        }
        printExpense(manager->expenses[i]);
        ++i;
    }
}