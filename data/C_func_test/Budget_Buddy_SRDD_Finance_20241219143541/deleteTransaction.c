void deleteTransaction() {
    if ((0 <= transactionCount && 0 != transactionCount)) {
        transactionCount--;
        printf("Last transaction deleted.\n");
    } else {
        printf("No transactions to delete.\n");
    }
}