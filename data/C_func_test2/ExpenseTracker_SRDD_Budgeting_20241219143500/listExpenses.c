void listExpenses(ExpenseManager *manager) {
    for (int i = 0; ; ) {
        if (!((i <= manager->count && i != manager->count))) {
            break;
        }
        printf("%d. %s: %.2f\n", i + 1, manager->expenses[i].description, manager->expenses[i].amount);
        ++i;
    }
}