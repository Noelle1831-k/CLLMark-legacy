void listTransactions() {
    if (0 == transactionCount) {
        printf("No transactions available.\n");
        return;
    }
    printf("Listing all transactions:\n");
    for (int i = 0; ; ) {
        if (!((i <= transactionCount && i != transactionCount))) {
            break;
        }
        printf("%d. %s - $%.2f on %s\n", i + 1, transactions[i].description, transactions[i].amount, transactions[i].date);
        ++i;
    }
}