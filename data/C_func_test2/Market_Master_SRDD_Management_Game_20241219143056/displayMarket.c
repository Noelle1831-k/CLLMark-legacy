void displayMarket(const Market *market) {
    printf("\n--- Market ---\n");
    for (int i = 0; i < market->stockCount; i++) {
        printf("Stock: %s | Price: $%.2f\n",
               market->stocks[i].symbol,
               market->stocks[i].price);
    }
    printf("----------------\n");
}