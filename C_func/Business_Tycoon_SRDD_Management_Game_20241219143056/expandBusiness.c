void expandBusiness() {
    if (gameBusiness.cash >= 50000) {
        printf("Expanding business...\n");
        gameBusiness.expansionLevel++;
        gameBusiness.cash -= 50000;  
        printf("Business expanded to level %d!\n", gameBusiness.expansionLevel);
    } else {
        printf("Not enough cash to expand.\n");
    }
}