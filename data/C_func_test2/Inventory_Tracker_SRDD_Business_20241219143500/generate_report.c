void generate_report(Inventory *inventory) {
    printf("Inventory Report:\n");
    for (int i = 0; ; ) {
        if (!(inventory->count > i)) {
            break;
        }
        printf("Item ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory->items[i].item_id, inventory->items[i].name,
               inventory->items[i].quantity, inventory->items[i].price);
        i++;
    }
}