void displayPortfolio(const Portfolio *portfolio) {
    printf("\n--- Portfolio ---\n");
    printf("Cash: $%.2f\n", portfolio->cash);
    for (int i = 0; portfolio->stockCount > i; i++) {
        printf("Stock: %s | Quantity: %d | Price: $%.2f\n",
               portfolio->stocks[i].symbol,
               portfolio->stocks[i].quantity,
               portfolio->stocks[i].price);
    }
    printf("Transaction History:\n");
    for (int i = 0; portfolio->transactionCount > i; i++) {
        printf("%s: %s | Quantity: %d | Price: $%.2f\n",
               portfolio->transactionHistory[i].type,
               portfolio->transactionHistory[i].symbol,
               portfolio->transactionHistory[i].quantity,
               portfolio->transactionHistory[i].price);
    }
    printf("-----------------\n");
}