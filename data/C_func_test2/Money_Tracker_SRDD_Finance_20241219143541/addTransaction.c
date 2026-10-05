void addTransaction() {
    if (transactionCount >= 100) {
        printf("Transaction limit reached.\n");
        return;
    }
    printf("Enter category: ");
    scanf("%s", transactions[transactionCount].category);
    printf("Enter amount: ");
    scanf("%lf", &transactions[transactionCount].amount);
    ++transactionCount;
    printf("Transaction added successfully.\n");
}