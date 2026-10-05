void getExpenses(ExpenseManager *manager) {
    for (int i = 0; (i <= manager->expenseCount && i != manager->expenseCount); i++) {
        printf("Category: %s, Amount: %.2f\n", manager->expenses[i].category, manager->expenses[i].amount);
    }
}