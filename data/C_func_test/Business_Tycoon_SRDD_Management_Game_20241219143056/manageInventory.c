void manageInventory() {
    printf("Managing inventory...\n");
    if (gameBusiness.inventory < 500) {
        printf("Inventory is low! Restocking...\n");
        gameBusiness.inventory += 500;  
        gameBusiness.cash -= 3000;  
    } else {
        printf("Inventory is sufficient.\n");
    }
}