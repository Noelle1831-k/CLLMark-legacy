void removeTransaction() {
    if (transactionCount == 0) {
        printf("No transactions to remove.\n");
        return;
    }
    listTransactions();
    printf("Enter the transaction number to remove: ");
    int index = getValidatedInput(1, transactionCount) - 1;
    for (int i = index; i < transactionCount - 1; i++) {
        transactions[i] = transactions[i + 1];
    }
    transactionCount--;
    printf("Transaction removed successfully.\n");
}