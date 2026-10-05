void deleteExpense() {
    int expenseIndex;
    printf("Enter the index of the expense to delete (1-%d): ", expenseCount);
    if (scanf("%d", &expenseIndex) != 1 || expenseIndex < 1 || expenseIndex > expenseCount) {
        printf("Invalid expense index.\n");
        waitForInput();
        return;
    }
    expenseIndex--; 
    for (int i = expenseIndex; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expenseCount--;
    printf("Expense deleted successfully!\n");
}