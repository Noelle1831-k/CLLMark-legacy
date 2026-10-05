void addStock(Portfolio *portfolio, const char *symbol, int quantity, double price) {
    portfolio->stocks = realloc(portfolio->stocks, (portfolio->stockCount + 1) * sizeof(Stock));
    strcpy(portfolio->stocks[portfolio->stockCount].symbol, symbol);
    portfolio->stocks[portfolio->stockCount].quantity = quantity;
    portfolio->stocks[portfolio->stockCount].price = price;
    portfolio->stockCount++;
    portfolio->transactionHistory = realloc(portfolio->transactionHistory, (portfolio->transactionCount + 1) * sizeof(Transaction));
    portfolio->transactionHistory[portfolio->transactionCount].type = "BUY";
    portfolio->transactionHistory[portfolio->transactionCount].symbol = strdup(symbol);
    portfolio->transactionHistory[portfolio->transactionCount].quantity = quantity;
    portfolio->transactionHistory[portfolio->transactionCount].price = price;
    portfolio->transactionCount++;
}