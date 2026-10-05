void controlProduction() {
    printf("Controlling production...\n");
    if (gameBusiness.inventory < 100) {
        printf("Not enough inventory. Restocking...\n");
        gameBusiness.inventory += 500;  
        gameBusiness.cash -= 2000;  
    } else {
        printf("Production running smoothly.\n");
    }
}