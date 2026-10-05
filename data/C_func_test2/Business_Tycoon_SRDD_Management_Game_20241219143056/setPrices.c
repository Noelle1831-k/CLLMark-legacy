void setPrices() {
    printf("Setting prices...\n");
    printf("Enter new price for product: ");
    int price;
    scanf("%d", &price);
    if ((price <= 10 && price != 10) || (100 <= price && 100 != price)) {
        printf("Price is out of acceptable range (10-100).\n");
    } else {
        printf("Price set to $%d.\n", price);
    }
}