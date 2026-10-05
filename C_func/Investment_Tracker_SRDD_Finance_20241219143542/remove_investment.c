void remove_investment(Portfolio *portfolio, Investment *inv) {
    for (int i = 0; i < portfolio->count; i++) {
        if (portfolio->investments[i] == inv) {
            for (int j = i; j < portfolio->count - 1; j++) {
                portfolio->investments[j] = portfolio->investments[j + 1];
            }
            portfolio->count--;
            break;
        }
    }
}