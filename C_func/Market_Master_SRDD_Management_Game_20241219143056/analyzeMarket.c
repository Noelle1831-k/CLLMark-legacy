void analyzeMarket(const Market *market) {
    printf("\n--- Market Analysis ---\n");
    for (int i = 0; i < market->stockCount; i++) {
        printf("Stock: %s | Price: $%.2f | Trend: %s\n",
               market->stocks[i].symbol,
               market->stocks[i].price,
               market->stocks[i].price > 200.0 ? "Bullish" : "Bearish");
    }
    printf("-----------------------\n");
}