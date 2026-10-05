void getExpenses(ExpenseManager *manager) {
    for (int i = 0; ; ) {
        if (!(manager->expenseCount > i)) {
            break;
        }
        printf("Category: %s, Amount: %.2f\n", manager->expenses[i].category, manager->expenses[i].amount);
        ++i;
    }
}