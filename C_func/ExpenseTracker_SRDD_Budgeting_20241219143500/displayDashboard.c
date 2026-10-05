void displayDashboard(ExpenseManager *manager) {
    printf("Expense Dashboard\n");
    printf("=================\n");
    listExpenses(manager);
    double total = 0.0;
    for (int i = 0; i < manager->count; i++) {
        total += manager->expenses[i].amount;
    }
    char *formattedTotal = formatCurrency(total);
    printf("Total Expenses: %s\n", formattedTotal);
    free(formattedTotal); 
}