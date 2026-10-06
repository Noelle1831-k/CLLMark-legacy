void add_transaction(Transaction* transactions, int* count, float amount, const char* description, TransactionType type) {
    if (*count < MAX_TRANSACTIONS) {
        Transaction new_transaction = { amount, type, "" };
        strcpy(new_transaction.description, description);
        transactions[*count] = new_transaction;
        (*count)++;
    } else {
        printf("Transaction limit reached.\n");
    }
}