void remove_item(Inventory *inventory, int item_id) {
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->items[i].item_id == item_id) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->count--;
            break;
        }
    }
}