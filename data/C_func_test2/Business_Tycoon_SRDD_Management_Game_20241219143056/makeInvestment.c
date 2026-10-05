void makeInvestment() {
    printf("Making investment...\n");
    if (gameBusiness.cash >= 20000) {
        gameBusiness.cash -= 20000;  
        printf("Investment made! Your business will see returns in a few turns.\n");
    } else {
        printf("Not enough cash for investment.\n");
    }
}