void get_transactions(Transaction *transactions, int count) {
    for (int i = 0; i < count; i++) {
        printf("Transaction %d: %s - %.2f - %s\n", i+1, transactions[i].type, transactions[i].amount, transactions[i].category);
    }
}