void addProduct() {
    if (productCount < 100) {
        printf("Enter product name: ");
        scanf("%s", inventory[productCount].name);
        printf("Enter stock quantity: ");
        scanf("%d", &inventory[productCount].stock);
        printf("Enter price: ");
        scanf("%f", &inventory[productCount].price);
        productCount++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory full!\n");
    }
}