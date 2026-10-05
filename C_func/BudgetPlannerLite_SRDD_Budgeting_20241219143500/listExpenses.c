void listExpenses() {
    if (expenseCount == 0) {
        printf("No expense entries found.\n");
        return;
    }
    printf("\nExpense Entries:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenseEntries[i].description, expenseEntries[i].amount);
    }
}