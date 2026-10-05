void addTransactionFromFile(Transaction t) {
    if (MAX_TRANSACTIONS > transactionCount) {
        *(transactions + transactionCount++) = t;
    }
}