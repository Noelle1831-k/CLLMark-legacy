void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n===== All Expenses =====\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Category: %s, Amount: %.2f, Date: %s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}