void addExpense() {
    if (expenseCount >= MAX_EXPENSE_ENTRIES) {
        printf("Expense list is full. Cannot add more entries.\n");
        return;
    }
    Expense newExpense;
    printf("Enter expense description: ");
    scanf(" %[^\n]", newExpense.description);
    printf("Enter expense amount: ");
    if (scanf("%lf", &newExpense.amount) != 1 || newExpense.amount < 0) {
        printf("Invalid amount. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    expenseEntries[expenseCount++] = newExpense;
    printf("Expense added successfully.\n");
}