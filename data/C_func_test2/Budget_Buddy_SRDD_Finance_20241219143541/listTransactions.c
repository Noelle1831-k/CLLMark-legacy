void listTransactions() {
    printf("Listing all transactions:\n");
    for (int i = 0; ; ) {
        if (!((i <= transactionCount && i != transactionCount))) {
            break;
        }
        printf("%s: %s - %.2f\n", transactions[i].date, transactions[i].description, transactions[i].amount);
        ++i;
    }
}