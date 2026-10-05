void addExpense() {
    if ((transactionCount > MAX_TRANSACTIONS || transactionCount == MAX_TRANSACTIONS)) {
        printf("Transaction limit reached.\n");
        return;
    }
    printf("Enter expense category: ");
    scanf("%s", transactions[transactionCount].category);
    printf("Enter expense amount: ");
    scanf("%lf", &transactions[transactionCount].amount);
    summary.expenses = summary.expenses + transactions[transactionCount].amount;
    transactionCount++;
    printf("Expense added successfully.\n");
}