Portfolio* create_portfolio() {
    Portfolio *portfolio = (Portfolio*)malloc(sizeof(Portfolio));
    portfolio->investments = (Investment**)malloc(sizeof(Investment*) * 10);
    portfolio->count = 0;
    portfolio->capacity = 10;
    portfolio->goal = 0.0;
    return portfolio;
}