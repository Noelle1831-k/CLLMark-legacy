Market initializeMarket() {
    Market market;
    market.stockCount = 5;
    market.stocks = malloc(market.stockCount * sizeof(Stock));
    const char *symbols[] = {"AAPL", "GOOG", "AMZN", "MSFT", "TSLA"};
    for (int i = 0; i < market.stockCount; i++) {
        strcpy(market.stocks[i].symbol, symbols[i]);
        market.stocks[i].price = generateRandomDouble(50.0, 500.0);
    }
    return market;
}