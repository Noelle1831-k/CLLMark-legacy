int main() {
    printf("Welcome to the Personalized Recipe Application!\n");
    char dietary_preferences[100];
    char flavor_preferences[100];
    get_user_preferences(dietary_preferences, flavor_preferences);
    Recipe *recipes = NULL;
    int recipe_count = load_recipes(&recipes);
    if (recipe_count == 0) {
        printf("No recipes found in the database.\n");
        return 1;
    }
    Recipe *filtered_recipes = NULL;
    int filtered_count = filter_recipes(recipes, recipe_count, dietary_preferences, flavor_preferences, &filtered_recipes);
    printf("\nFiltered Recipes:\n");
    for (int i = 0; i < filtered_count; i++) {
        printf("%d. %s\n", i + 1, filtered_recipes[i].name);
    }
    if (filtered_count > 0) {
        int choice;
        printf("\nEnter the number of the recipe you'd like to customize: ");
        scanf("%d", &choice);
        if (choice > 0 && choice <= filtered_count) {
            customize_recipe(&filtered_recipes[choice - 1]);
        } else {
            printf("Invalid choice. Returning to the main menu.\n");
        }
    } else {
        printf("No recipes available for customization.\n");
    }
    free(recipes);
    free(filtered_recipes);
    printf("\nThank you for using the Personalized Recipe Application!\n");
    return 0;
}