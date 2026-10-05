int filter_recipes(Recipe *recipes, int recipe_count, const char *dietary_preferences, const char *flavor_preferences, Recipe **filtered_recipes) {
    *filtered_recipes = malloc(recipe_count * sizeof(Recipe));
    int count = 0;
    for (int i = 0; i < recipe_count; i++) {
        if (string_compare(recipes[i].name, dietary_preferences) || string_compare(recipes[i].name, flavor_preferences)) {
            (*filtered_recipes)[count++] = recipes[i];
        }
    }
    return count;
}