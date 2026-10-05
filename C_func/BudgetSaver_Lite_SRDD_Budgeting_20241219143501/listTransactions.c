void listTransactions() {
    if (transactionCount == 0) {
        printf("No transactions available.\n");
        return;
    }
    printf("Listing all transactions:\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("%d. %s - $%.2f on %s\n", i + 1, transactions[i].description, transactions[i].amount, transactions[i].date);
    }
}