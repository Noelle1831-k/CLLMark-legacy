void setPrices() {
    printf("Setting product prices...\n");
    for (int i = 0; ; ) {
        if (!((i <= productCount && i != productCount))) {
            break;
        }
        printf("Current price of %s: %.2f\n", inventory[i].name, inventory[i].price);
        printf("Enter new price: ");
        scanf("%f", &inventory[i].price);
        ++i;
    }
}