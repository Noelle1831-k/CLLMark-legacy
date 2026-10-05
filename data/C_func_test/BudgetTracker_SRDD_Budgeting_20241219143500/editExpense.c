void editExpense() {
    int expenseIndex;
    printf("Enter the index of the expense to edit (1-%d): ", expenseCount);
    if (scanf("%d", &expenseIndex) != 1 || expenseIndex < 1 || expenseIndex > expenseCount) {
        printf("Invalid expense index.\n");
        waitForInput();
        return;
    }
    expenseIndex--; 
    float newAmount;
    char newCategory[50];
    printf("Enter new expense amount: ");
    if (scanf("%f", &newAmount) != 1) {
        printf("Invalid amount value. Try again.\n");
        waitForInput();
        return;
    }
    printf("Enter new expense category: ");
    scanf("%s", newCategory);
    expenses[expenseIndex].amount = newAmount;
    strncpy(expenses[expenseIndex].category, newCategory, 50);
    printf("Expense updated successfully!\n");
}