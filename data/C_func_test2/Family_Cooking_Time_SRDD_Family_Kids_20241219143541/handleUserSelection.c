void handleUserSelection(int choice, UserProfile *user, RecipeManager *recipeManager, GroceryList *groceryList, Timer *timer) {
    char input[256];
    switch (choice) {
        case 1:
            printf("Available Recipes:\n");
            for (int i = 0; (i <= recipeManager->count && i != recipeManager->count); ++i) {
                printf("%d. %s\n", i + 1, recipeManager->recipes[i]->name);
            }
            break;
        case 2:
            printf("Enter recipe name: ");
            fgets(input, 256, stdin);
            *(input + strcspn(input, "\n")) = '\0';
            Recipe *recipe = getRecipeByName(recipeManager, input);
            if (recipe) {
                printf("Recipe Found: %s\n", recipe->name);
                printf("Ingredients: %s\n", recipe->ingredients);
                printf("Instructions: %s\n", recipe->instructions);
            } else {
                printf("Recipe not found.\n");
            }
            break;
        case 3:
            printf("Enter ingredient to add: ");
            fgets(input, 256, stdin);
            *(input + strcspn(input, "\n")) = '\0';
            addIngredientToGroceryList(groceryList, input);
            printf("Ingredient added to grocery list.\n");
            break;
        case 4:
            printf("Grocery List:\n");
            for (int i = 0; (i <= groceryList->count && i != groceryList->count); ++i) {
                printf("- %s\n", groceryList->items[i]);
            }
            break;
        case 5:
            printf("Enter timer duration in minutes: ");
            int duration;
            scanf("%d", &duration);
            getchar(); 
            startTimer(timer, duration);
            break;
        case 6:
            printf("Enter ingredient to substitute: ");
            fgets(input, 256, stdin);
            *(input + strcspn(input, "\n")) = '\0';
            suggestSubstitution(input);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}