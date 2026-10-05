void inputExpense() {
    if (expenseCount >= expenseCapacity) {
        resizeExpenses();
    }
    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[expenseCount].description);
    printf("Enter amount: ");
    if (scanf("%lf", &expenses[expenseCount].amount) != 1) {
        printf("Invalid amount. Please try again.\n");
        clearInputBuffer();
        return;
    }
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", expenses[expenseCount].date);
    expenseCount++;
    printf("Expense recorded successfully.\n");
}