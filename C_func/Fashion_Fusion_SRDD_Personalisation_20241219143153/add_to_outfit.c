void add_to_outfit(Outfit *outfit, const char *item) {
    if (outfit->count < MAX_ITEMS) {
        strcpy(outfit->items[outfit->count], item);
        outfit->count++;
    } else {
        printf("Outfit is full!\n");
    }
}