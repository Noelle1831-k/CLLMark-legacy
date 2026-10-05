void deleteTransaction() {
    if (transactionCount > 0) {
        transactionCount--;
        printf("Last transaction deleted.\n");
    } else {
        printf("No transactions to delete.\n");
    }
}