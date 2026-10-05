int main(int argc, char *argv[]) {
    UserPreferences userPrefs;
    Recipe recipe;
    MealPlanner mealPlanner;
    CookingTips cookingTips;
    cout << "Welcome to the Personalized Cooking Guidance Application!" << endl;
    userPrefs.setPreferences();
    vector<string> preferences = userPrefs.getPreferences();
    recipe.generateRecipe(preferences);
    recipe.getNutritionalInfo();
    mealPlanner.planMeals();
    mealPlanner.generateGroceryList();
    cookingTips.getTips();
    cout << "Thank you for using the application. Happy Cooking!" << endl;
    return 0;
}