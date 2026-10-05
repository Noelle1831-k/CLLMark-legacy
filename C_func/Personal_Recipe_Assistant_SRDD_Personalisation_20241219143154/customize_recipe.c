void customize_recipe(Recipe *recipe) {
    printf("\nCustomizing Recipe: %s\n", recipe->name);
    char ingredient[50];
    char new_ingredient[50];
    float factor;
    printf("Enter an ingredient to adjust: ");
    scanf("%s", ingredient);
    printf("Enter adjustment factor (e.g., 1.5 for 50%% more): ");
    scanf("%f", &factor);
    adjust_ingredient_quantities(recipe, ingredient, factor);
    printf("Enter an ingredient to substitute: ");
    scanf("%s", ingredient);
    printf("Enter the new ingredient: ");
    scanf("%s", new_ingredient);
    substitute_ingredients(recipe, ingredient, new_ingredient);
    printf("Recipe customization complete.\n");
}