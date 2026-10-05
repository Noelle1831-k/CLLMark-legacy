void Application::addRecipeToDatabase() {
    cout << "Adding recipes to the database..." << endl;
    Recipe recipe1("Spicy Vegetarian Chili");
    recipe1.addIngredient("Beans", 2.0, "cups");
    recipe1.addIngredient("Tomato", 1.0, "cup");
    recipe1.addTag("vegetarian");
    recipe1.addTag("spicy");
    recipeDatabase.addRecipe(recipe1);
}