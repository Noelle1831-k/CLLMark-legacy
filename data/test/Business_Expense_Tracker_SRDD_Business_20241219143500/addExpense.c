void addExpense() {
    if (expenseCount >= 100) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    Expense newExpense;
    printf("Enter description: ");
    scanf(" %[^\n]", newExpense.description);
    printf("Enter category: ");
    scanf(" %[^\n]", newExpense.category);
    printf("Enter amount: ");
    scanf("%lf", &newExpense.amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]", newExpense.date);
    expenses[expenseCount++] = newExpense;
    printf("Expense added successfully!\n");
}