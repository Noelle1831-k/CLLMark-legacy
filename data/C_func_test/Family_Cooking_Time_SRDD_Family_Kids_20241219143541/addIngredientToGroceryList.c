void addIngredientToGroceryList(GroceryList *list, const char *ingredient) {
    list->items = (char **)realloc(list->items, sizeof(char *) * (list->count + 1));
    list->items[list->count++] = strdup(ingredient);
}