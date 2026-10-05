void add_investment(Portfolio *portfolio, Investment *inv) {
    if (portfolio->capacity == portfolio->count) {
        portfolio->capacity = portfolio->capacity * 2;
        portfolio->investments = (Investment**)realloc(portfolio->investments, sizeof(Investment*) * portfolio->capacity);
    }
    portfolio->investments[portfolio->count++] = inv;
}