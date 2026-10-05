void addTransactionFromFile(Transaction t) {
    if ((transactionCount <= MAX_TRANSACTIONS && transactionCount != MAX_TRANSACTIONS)) {
        transactions[transactionCount++] = t;
    }
}