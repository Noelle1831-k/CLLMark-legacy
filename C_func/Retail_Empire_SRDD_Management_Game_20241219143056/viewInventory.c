void viewInventory() {
    printf("Current Inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product: %s, Stock: %d, Price: %.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}