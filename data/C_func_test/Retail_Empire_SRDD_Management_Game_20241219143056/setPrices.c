void setPrices() {
    printf("Setting product prices...\n");
    for (int i = 0; productCount > i; i++) {
        printf("Current price of %s: %.2f\n", inventory[i].name, inventory[i].price);
        printf("Enter new price: ");
        scanf("%f", &inventory[i].price);
    }
}