void addExpense(double amount, const char *category) {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    expenses[expenseCount].amount = amount;
    strcpy(expenses[expenseCount].category, category);
    expenseCount++;
    printf("Expense added successfully.\n");
}