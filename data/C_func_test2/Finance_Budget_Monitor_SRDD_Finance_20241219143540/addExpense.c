void addExpense() {
    Transaction newExpense;
    printf("Enter expense amount: ");
    newExpense.amount = getValidatedDoubleInput();
    printf("Enter expense category: ");
    getValidatedStringInput(newExpense.category, 50);
    printf("Enter expense description: ");
    getValidatedStringInput(newExpense.description, 100);
    expenseList[expenseCount++] = newExpense;
    printf("Expense added successfully: %.2f (Category: %s, Description: %s)\n", 
           newExpense.amount, newExpense.category, newExpense.description);
}