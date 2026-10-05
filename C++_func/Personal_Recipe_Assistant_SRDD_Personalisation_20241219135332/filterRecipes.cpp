vector<Recipe> RecipeDatabase::filterRecipes(const vector<string>& restrictions) const {
    vector<Recipe> filteredRecipes;
    for (vector<Recipe>::const_iterator it = recipes.begin(); it != recipes.end(); ++it) {
        if (it->matchesTags(restrictions)) {
            filteredRecipes.push_back(*it);
        }
    }
    return filteredRecipes;
}