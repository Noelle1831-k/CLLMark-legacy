int main() {
    printf("Welcome to FamilyCookingTime!\n");
    UserProfile *user = createUserProfile("John Doe", "johndoe@example.com");
    RecipeManager *recipeManager = createRecipeManager();
    GroceryList *groceryList = createGroceryList();
    Timer *timer = createTimer();
    addRecipe(recipeManager, "Spaghetti Bolognese", "Pasta, Tomato Sauce, Ground Beef", "Cook pasta, prepare sauce, mix together.");
    addRecipe(recipeManager, "Vegetable Stir Fry", "Mixed Vegetables, Soy Sauce, Tofu", "Stir fry vegetables, add tofu, serve with rice.");
    addRecipe(recipeManager, "Pancakes", "Flour, Eggs, Milk, Sugar", "Mix ingredients, cook on a pan, and serve with syrup.");
    int choice = 0;
    do {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
        getchar(); 
        handleUserSelection(choice, user, recipeManager, groceryList, timer);
    } while (choice != 0);
    freeUserProfile(user);
    freeRecipeManager(recipeManager);
    freeGroceryList(groceryList);
    freeTimer(timer);
    printf("Thank you for using FamilyCookingTime! Happy cooking!\n");
    return 0;
}