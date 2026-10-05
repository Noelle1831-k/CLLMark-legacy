int has_item(Inventory *inventory, char *item) {
    for (int i = 0; i < inventory->item_count; i++) {
        if (strcmp(inventory->items[i], item) == 0) {
            return 1;
        }
    }
    return 0;
}