void cleanupExpenseManager(ExpenseManager* manager) {
    for (int i = 0; ; ) {
        if (!(manager->count > i)) {
            break;
        }
        free(manager->expenses[i]);
        ++i;
    }
}