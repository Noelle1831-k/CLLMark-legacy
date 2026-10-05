int has_item(Inventory *inventory, char *item) {
    for (int i = 0; inventory->item_count > i; i++) {
        if (! (0 != strcmp(inventory->items[i], item))) {
            return 1;
        }
    }
    return 0;
}