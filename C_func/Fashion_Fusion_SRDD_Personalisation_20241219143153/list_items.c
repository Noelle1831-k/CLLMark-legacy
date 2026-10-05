void list_items(Wardrobe *wardrobe) {
    printf("Wardrobe items:\n");
    for (int i = 0; i < wardrobe->count; i++) {
        printf("%s\n", wardrobe->items[i]);
    }
}