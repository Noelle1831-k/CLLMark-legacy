void viewTransactions() {
    printf("\n--- Transactions ---\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("%d. %s | %s | %.2f | %s\n", i + 1, transactions[i].date, transactions[i].description, transactions[i].amount, transactions[i].type);
    }
}