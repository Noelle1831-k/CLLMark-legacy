void freeGroceryList(GroceryList *list) {
    if (list) {
        for (int i = 0; i < list->count; i++) {
            free(list->items[i]);
        }
        free(list->items);
        free(list);
    }
}