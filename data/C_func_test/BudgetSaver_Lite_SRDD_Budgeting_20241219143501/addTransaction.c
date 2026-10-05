void addTransaction() {
    if (transactionCount >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }
    Transaction newTransaction;
    printf("Enter transaction description: ");
    scanf("%s", newTransaction.description);
    printf("Enter transaction amount: ");
    scanf("%lf", &newTransaction.amount);
    printf("Enter transaction date (YYYY-MM-DD): ");
    scanf("%s", newTransaction.date);
    transactions[transactionCount++] = newTransaction;
    printf("Transaction added successfully.\n");
}