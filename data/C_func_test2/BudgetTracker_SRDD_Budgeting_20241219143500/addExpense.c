void addExpense(float amount, const char *category) {
    if (expenseCount < 100) {
        expenses[expenseCount].amount = amount;
        strncpy(expenses[expenseCount].category, category, 50);
        expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Error: Expense limit reached!\n");
    }
}