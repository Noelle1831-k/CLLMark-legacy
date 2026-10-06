void listExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n--- Expense List ---\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. %s | %s | $%.2f | %s\n", i + 1, expenses[i].description, expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}