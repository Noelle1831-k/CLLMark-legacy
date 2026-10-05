void addExpense(double amount, const char *description) {
    if (expenseCount < 100) {
        expenses[expenseCount].amount = amount;
        strncpy(expenses[expenseCount].description, description, sizeof(expenses[expenseCount].description) - 1);
        expenses[expenseCount].description[sizeof(expenses[expenseCount].description) - 1] = '\0'; 
        expenseCount++;
        printf("Expense added successfully.\n");
    } else {
        printf("Expense list is full.\n");
    }
}