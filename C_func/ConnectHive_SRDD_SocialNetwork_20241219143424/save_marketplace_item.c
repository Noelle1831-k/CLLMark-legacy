void save_marketplace_item(MarketplaceItem item) {
    FILE *file = fopen("marketplace.dat", "ab");
    if (!file) {
        printf("Error: Unable to save item.\n");
        return;
    }
    fwrite(&item, sizeof(MarketplaceItem), 1, file);
    fclose(file);
}