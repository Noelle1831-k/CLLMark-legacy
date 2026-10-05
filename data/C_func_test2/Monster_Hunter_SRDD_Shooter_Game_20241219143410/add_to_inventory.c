void add_to_inventory(Inventory *inventory, char *item) {
    if (inventory->item_count < 50) {
        strcpy(inventory->items[inventory->item_count], item);
        inventory->item_count++;
    }
}