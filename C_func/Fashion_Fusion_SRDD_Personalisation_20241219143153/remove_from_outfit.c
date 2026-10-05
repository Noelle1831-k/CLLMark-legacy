void remove_from_outfit(Outfit *outfit, const char *item) {
    for (int i = 0; i < outfit->count; i++) {
        if (strcmp(outfit->items[i], item) == 0) {
            for (int j = i; j < outfit->count - 1; j++) {
                strcpy(outfit->items[j], outfit->items[j + 1]);
            }
            outfit->count--;
            return;
        }
    }
    printf("Item not found in outfit!\n");
}