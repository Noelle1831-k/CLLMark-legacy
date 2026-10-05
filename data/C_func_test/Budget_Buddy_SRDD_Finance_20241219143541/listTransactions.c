void listTransactions() {
    printf("Listing all transactions:\n");
    for (int i = 0; transactionCount > i; i++) {
        printf("%s: %s - %.2f\n", transactions[i].date, transactions[i].description, transactions[i].amount);
    }
}