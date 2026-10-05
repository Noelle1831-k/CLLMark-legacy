void optimizeOperations() {
    printf("Optimizing operations...\n");
    if (gameBusiness.cash >= 20000) {
        gameBusiness.cash -= 20000;  
        printf("Operations optimized. Reduced costs and increased efficiency!\n");
    } else {
        printf("Not enough cash to optimize operations.\n");
    }
}