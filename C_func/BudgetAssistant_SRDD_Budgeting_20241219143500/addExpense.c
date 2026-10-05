void addExpense() {
    if (expenseCount < 100) {
        printf("Enter expense category: ");
        scanf("%s", expenses[expenseCount].category);
        printf("Enter expense amount: ");
        expenses[expenseCount].amount = getDoubleInput();
        expenseCount++;
        printf("Expense added successfully.\n");
    } else {
        printf("Expense list is full.\n");
    }
}