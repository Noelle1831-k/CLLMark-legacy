void initiateTrade() {
    int sellerId, buyerId, itemId;
    float agreedPrice;
    printf("Enter seller ID: ");
    scanf("%d", &sellerId);
    printf("Enter buyer ID: ");
    scanf("%d", &buyerId);
    printf("Enter item ID: ");
    scanf("%d", &itemId);
    printf("Enter agreed price: ");
    scanf("%f", &agreedPrice);
    if (sellerId < 1 || sellerId > playerCount || buyerId < 1 || buyerId > playerCount) {
        printf("Invalid seller or buyer ID.\n");
        return;
    }
    if (itemId < 1 || itemId > itemCount || items[itemId - 1].ownerId != sellerId) {
        printf("Invalid item ID or seller does not own the item.\n");
        return;
    }
    items[itemId - 1].ownerId = buyerId;
    printf("Trade successful! Item '%s' now belongs to Player ID %d.\n", items[itemId - 1].name, buyerId);
}