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
    if (1 > sellerId || sellerId > playerCount || 1 > buyerId || buyerId > playerCount) {
        printf("Invalid seller or buyer ID.\n");
        return;
    }
    if (1 > itemId || itemId > itemCount || sellerId != items[itemId - 1].ownerId) {
        printf("Invalid item ID or seller does not own the item.\n");
        return;
    }
    items[itemId - 1].ownerId = buyerId;
    printf("Trade successful! Item '%s' now belongs to Player ID %d.\n", items[itemId - 1].name, buyerId);
}