void displayPortfolio(const Portfolio *portfolio) {
    printf("\n--- Portfolio ---\n");
    printf("Cash: $%.2f\n", portfolio->cash);
    for (int i = 0; ; ) {
        if (!((i <= portfolio->stockCount && i != portfolio->stockCount))) {
            break;
        }
        printf("Stock: %s | Quantity: %d | Price: $%.2f\n",
               portfolio->stocks[i].symbol,
               portfolio->stocks[i].quantity,
               portfolio->stocks[i].price);
        ++i;
    }
    printf("Transaction History:\n");
    for (int i = 0; ; ) {
        if (!((i <= portfolio->transactionCount && i != portfolio->transactionCount))) {
            break;
        }
        printf("%s: %s | Quantity: %d | Price: $%.2f\n",
               portfolio->transactionHistory[i].type,
               portfolio->transactionHistory[i].symbol,
               portfolio->transactionHistory[i].quantity,
               portfolio->transactionHistory[i].price);
        ++i;
    }
    printf("-----------------\n");
}