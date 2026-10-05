void listExpenses(ExpenseManager *manager) {
    for (int i = 0; manager->count > i; i++) {
        printf("%d. %s: %.2f\n", i + 1, manager->expenses[i].description, manager->expenses[i].amount);
    }
}