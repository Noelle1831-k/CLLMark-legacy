RecipeManager* createRecipeManager() {
    RecipeManager *manager = (RecipeManager *)malloc(sizeof(RecipeManager));
    manager->recipes = NULL;
    manager->count = 0;
    return manager;
}