void deleteExpense() {
    int index;
    printf("Enter the index of the expense to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > expenseCount) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index - 1; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expenseCount--;
    printf("Expense deleted successfully.\n");
}