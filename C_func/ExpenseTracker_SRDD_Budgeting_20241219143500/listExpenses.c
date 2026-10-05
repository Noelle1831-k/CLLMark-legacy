void listExpenses(ExpenseManager *manager) {
    for (int i = 0; i < manager->count; i++) {
        printf("%d. %s: %.2f\n", i + 1, manager->expenses[i].description, manager->expenses[i].amount);
    }
}