void display_all_listings() {
    MarketplaceItem items[MAX_ITEMS];
    int count = load_all_marketplace_items(items);
    printf("\n==== Marketplace Listings ====\n");
    if (count == 0) {
        printf("No listings available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Description: %s, Price: $%.2f\n",
               items[i].name, items[i].description, items[i].price);
    }
    printf("=============================\n");
}