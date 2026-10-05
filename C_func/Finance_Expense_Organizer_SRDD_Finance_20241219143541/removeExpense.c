void removeExpense(ExpenseManager *manager, int index) {
    if (index >= 0 && index < manager->count) {
        destroyExpense(manager->expenses[index]);
        for (int i = index; i < manager->count - 1; ++i) {
            manager->expenses[i] = manager->expenses[i + 1];
        }
        manager->count--;
    } else {
        printf("Invalid expense index.\n");
    }
}