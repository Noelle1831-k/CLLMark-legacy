vector<Recipe> RecipeDatabase::searchRecipesByName(const string& name) const {
    vector<Recipe> foundRecipes;
    for (vector<Recipe>::const_iterator it = recipes.begin(); it != recipes.end(); ++it) {
        if (it->getName().find(name) != string::npos) {
            foundRecipes.push_back(*it);
        }
    }
    return foundRecipes;
}