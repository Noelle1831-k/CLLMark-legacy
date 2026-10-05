void setPrices() {
    printf("Setting prices...\n");
    printf("Enter new price for product: ");
    int price;
    scanf("%d", &price);
    if (10 > price || price > 100) {
        printf("Price is out of acceptable range (10-100).\n");
    } else {
        printf("Price set to $%d.\n", price);
    }
}