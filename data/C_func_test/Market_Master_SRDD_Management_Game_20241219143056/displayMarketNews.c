void displayMarketNews(const Market *market) {
    printf("\n--- Market News ---\n");
    printf("Breaking: Market trends are showing mixed signals today, but certain stocks like %s and %s are showing positive momentum.\n",
           market->stocks[0].symbol, market->stocks[2].symbol);
    printf("Watch out for volatility in tech stocks due to upcoming earnings reports.\n");
    printf("-------------------\n");
}