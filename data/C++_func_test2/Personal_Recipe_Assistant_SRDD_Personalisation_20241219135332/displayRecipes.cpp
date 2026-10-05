void Application::displayRecipes() {
    vector<string> restrictions = userPreferences.getRestrictions();
    vector<Recipe> filteredRecipes = recipeDatabase.filterRecipes(restrictions);
    cout << "Filtered Recipes:" << endl;
    for (vector<Recipe>::const_iterator it = filteredRecipes.begin(); it != filteredRecipes.end(); ++it) {
        it->displayRecipe();
    }
}