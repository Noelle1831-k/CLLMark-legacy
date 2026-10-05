void add_item(Wardrobe *wardrobe, const char *item) {
    if (wardrobe->count < MAX_ITEMS) {
        strcpy(wardrobe->items[wardrobe->count], item);
        wardrobe->count++;
    } else {
        printf("Wardrobe is full!\n");
    }
}