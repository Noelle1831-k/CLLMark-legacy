void sortTransactions() {
    for (int i = 0; i < transactionCount - 1; i++) {
        for (int j = 0; j < transactionCount - i - 1; j++) {
            if (strcmp(transactions[j].date, transactions[j + 1].date) > 0) {
                Transaction temp = transactions[j];
                transactions[j] = transactions[j + 1];
                transactions[j + 1] = temp;
            }
        }
    }
    printf("Transactions sorted by date.\n");
}