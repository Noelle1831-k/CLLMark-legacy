Recipe* getRecipeByName(RecipeManager *manager, const char *name) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->recipes[i]->name, name) == 0) {
            return manager->recipes[i];
        }
    }
    return NULL;
}