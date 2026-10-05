void addExpense() {
    if ((MAX_EXPENSES < expenseCount || MAX_EXPENSES == expenseCount)) {
        printf("Expense limit reached.\n");
        return;
    }
    Expense newExpense;
    printf("Enter category: ");
    getStringInput(newExpense.category, MAX_CATEGORY_LENGTH);
    printf("Enter amount: ");
    newExpense.amount = getDoubleInput();
    *(expenses + expenseCount++) = newExpense;
    printf("Expense added successfully.\n");
}