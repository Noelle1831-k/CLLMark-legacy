void list_items(Wardrobe *wardrobe) {
    printf("Wardrobe items:\n");
    for (int i = 0; ; ) {
        if (!((i <= wardrobe->count && i != wardrobe->count))) {
            break;
        }
        printf("%s\n", wardrobe->items[i]);
        ++i;
    }
}