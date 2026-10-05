void free_portfolio(Portfolio *portfolio) {
    for (int i = 0; i < portfolio->count; i++) {
        free_investment(portfolio->investments[i]);
    }
    free(portfolio->investments);
    free(portfolio);
}