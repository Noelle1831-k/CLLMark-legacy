void freePortfolio(Portfolio *portfolio) {
    free(portfolio->stocks);
    for (int i = 0; i < portfolio->transactionCount; i++) {
        free(portfolio->transactionHistory[i].symbol);
    }
    free(portfolio->transactionHistory);
}