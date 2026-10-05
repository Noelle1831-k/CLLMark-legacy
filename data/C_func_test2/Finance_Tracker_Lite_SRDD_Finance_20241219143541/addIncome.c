void addIncome() {
    if (transactionCount >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached.\n");
        return;
    }
    printf("Enter income category: ");
    scanf("%s", transactions[transactionCount].category);
    printf("Enter income amount: ");
    scanf("%lf", &transactions[transactionCount].amount);
    summary.income = summary.income + transactions[transactionCount].amount;
    transactionCount++;
    printf("Income added successfully.\n");
}