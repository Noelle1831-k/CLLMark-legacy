void freeRecipeManager(RecipeManager *manager) {
    if (manager) {
        for (int i = 0; i < manager->count; i++) {
            free(manager->recipes[i]->name);
            free(manager->recipes[i]->ingredients);
            free(manager->recipes[i]->instructions);
            free(manager->recipes[i]);
        }
        free(manager->recipes);
        free(manager);
    }
}