void removeStock(Portfolio *portfolio, int index) {
    for (int i = index; i < portfolio->stockCount - 1; i++) {
        portfolio->stocks[i] = portfolio->stocks[i + 1];
    }
    portfolio->stockCount--;
    portfolio->stocks = realloc(portfolio->stocks, portfolio->stockCount * sizeof(Stock));
}