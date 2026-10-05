void substitute_ingredients(Recipe *recipe, const char *old_ingredient, const char *new_ingredient) {
    for (int i = 0; i < recipe->ingredient_count; i++) {
        if (string_compare(recipe->ingredients[i], old_ingredient)) {
            strcpy(recipe->ingredients[i], new_ingredient);
        }
    }
}