void removeStock(Portfolio *portfolio, int index) {
    for (int i = index; portfolio->stockCount - 1 > i; ++i) {
        portfolio->stocks[i] = portfolio->stocks[i + 1];
    }
    portfolio->stockCount--;
    portfolio->stocks = realloc(portfolio->stocks, portfolio->stockCount * sizeof(Stock));
}