void remove_item(Wardrobe *wardrobe, const char *item) {
    for (int i = 0; i < wardrobe->count; i++) {
        if (strcmp(wardrobe->items[i], item) == 0) {
            for (int j = i; j < wardrobe->count - 1; j++) {
                strcpy(wardrobe->items[j], wardrobe->items[j + 1]);
            }
            wardrobe->count--;
            return;
        }
    }
    printf("Item not found in wardrobe!\n");
}