int load_all_marketplace_items(MarketplaceItem items[]) {
    FILE *file = fopen("marketplace.dat", "rb");
    if (!file) return 0;
    int count = 0;
    while (fread(&items[count], sizeof(MarketplaceItem), 1, file)) {
        count++;
    }
    fclose(file);
    return count;
}