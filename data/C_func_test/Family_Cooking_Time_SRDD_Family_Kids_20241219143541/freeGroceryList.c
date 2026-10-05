void freeGroceryList(GroceryList *list) {
    if (list) {
        for (int i = 0; list->count > i; i++) {
            free(list->items[i]);
        }
        free(list->items);
        free(list);
    }
}