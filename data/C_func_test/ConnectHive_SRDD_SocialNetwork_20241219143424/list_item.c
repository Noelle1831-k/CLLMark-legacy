void list_item() {
    MarketplaceItem item;
    printf("\nEnter item name: ");
    scanf(" %[^\n]", item.name);
    printf("Enter item description: ");
    scanf(" %[^\n]", item.description);
    printf("Enter price (numeric value): ");
    while (scanf("%lf", &item.price) != 1) {
        while (getchar() != '\n'); 
        printf("Invalid input. Please enter a valid price: ");
    }
    save_marketplace_item(item);
    printf("Item listed successfully!\n");
}