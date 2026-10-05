void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached.\n");
        return;
    }
    Expense newExpense;
    printf("Enter category: ");
    getStringInput(newExpense.category, MAX_CATEGORY_LENGTH);
    printf("Enter amount: ");
    newExpense.amount = getDoubleInput();
    expenses[expenseCount++] = newExpense;
    printf("Expense added successfully.\n");
}