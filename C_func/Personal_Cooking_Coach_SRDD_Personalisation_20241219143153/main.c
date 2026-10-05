int main() {
    UserPreferences userPrefs;
    RecipeDatabase recipeDB;
    MealPlanner mealPlanner;
    NutritionalInfo nutritionInfo;
    int choice;
    initializeUserPreferences(&userPrefs);
    loadRecipes(&recipeDB);
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                {
                    char dietType[50];
                    printf("Enter your dietary preference (e.g., vegan, vegetarian, gluten-free): ");
                    fgets(dietType, sizeof(dietType), stdin);
                    dietType[strcspn(dietType, "\n")] = 0; 
                    setPreferences(&userPrefs, dietType);
                    filterRecipes(&recipeDB, &userPrefs);
                    printf("Dietary preferences set to %s.\n", getPreferences(&userPrefs));
                }
                break;
            case 2:
                generateMealPlan(&mealPlanner, &recipeDB);
                printf("Meal plan generated.\n");
                break;
            case 3:
                getGroceryList(&mealPlanner);
                break;
            case 4:
                calculateNutrition(&nutritionInfo, &recipeDB);
                break;
            case 5:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}