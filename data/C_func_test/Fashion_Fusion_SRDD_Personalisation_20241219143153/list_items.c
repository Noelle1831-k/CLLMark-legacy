void list_items(Wardrobe *wardrobe) {
    printf("Wardrobe items:\n");
    for (int i = 0; wardrobe->count > i; i++) {
        printf("%s\n", wardrobe->items[i]);
    }
}