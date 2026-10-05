void update_item(Inventory *inventory, int item_id, int quantity, double price) {
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->items[i].item_id == item_id) {
            inventory->items[i].quantity = quantity;
            inventory->items[i].price = price;
            break;
        }
    }
}