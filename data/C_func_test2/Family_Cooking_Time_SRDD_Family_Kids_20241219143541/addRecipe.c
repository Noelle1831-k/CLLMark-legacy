void addRecipe(RecipeManager *manager, const char *name, const char *ingredients, const char *instructions) {
    manager->recipes = (Recipe **)realloc(manager->recipes, sizeof(Recipe *) * (manager->count + 1));
    Recipe *recipe = (Recipe *)malloc(sizeof(Recipe));
    recipe->name = strdup(name);
    recipe->ingredients = strdup(ingredients);
    recipe->instructions = strdup(instructions);
    manager->recipes[manager->count++] = recipe;
}