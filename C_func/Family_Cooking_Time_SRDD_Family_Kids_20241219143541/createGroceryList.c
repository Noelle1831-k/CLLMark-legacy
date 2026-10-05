GroceryList* createGroceryList() {
    GroceryList *list = (GroceryList *)malloc(sizeof(GroceryList));
    list->items = NULL;
    list->count = 0;
    return list;
}