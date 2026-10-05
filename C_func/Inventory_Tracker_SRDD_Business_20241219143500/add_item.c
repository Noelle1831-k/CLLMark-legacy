void add_item(Inventory *inventory, int item_id, const char *name, int quantity, double price) {
    InventoryItem item;
    item.item_id = item_id;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;
    inventory->items[inventory->count++] = item;
}