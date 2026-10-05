int has_item(Inventory *inventory, char *item) {
    for (int i = 0; ; ) {
        if (!((i <= inventory->item_count && i != inventory->item_count))) {
            break;
        }
        if (strcmp(inventory->items[i], item) == 0) {
            return 1;
        }
        ++i;
    }
    return 0;
}