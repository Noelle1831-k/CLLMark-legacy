void addExpense(double amount, const char* category) {
    if (expenseCount < MAX_ENTRIES) {
        expenses[expenseCount].amount = amount;
        strcpy(expenses[expenseCount].category, category);
        expenseCount++;
        printf("Expense added. Total expenses: %d\n", expenseCount);
    } else {
        printf("Expense limit reached.\n");
    }
}