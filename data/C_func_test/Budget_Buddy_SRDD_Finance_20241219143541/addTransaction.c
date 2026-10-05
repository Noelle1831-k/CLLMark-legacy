void addTransaction() {
    if (transactionCount < 100) {
        printf("Enter transaction description: ");
        fgets(transactions[transactionCount].description, sizeof(transactions[transactionCount].description), stdin);
        transactions[transactionCount].description[strcspn(transactions[transactionCount].description, "\n")] = '\0';  
        printf("Enter transaction amount: ");
        scanf("%lf", &transactions[transactionCount].amount);
        getchar();  
        printf("Enter transaction date (YYYY-MM-DD): ");
        fgets(transactions[transactionCount].date, sizeof(transactions[transactionCount].date), stdin);
        transactions[transactionCount].date[strcspn(transactions[transactionCount].date, "\n")] = '\0';  
        transactionCount++;
    } else {
        printf("Transaction limit reached.\n");
    }
}