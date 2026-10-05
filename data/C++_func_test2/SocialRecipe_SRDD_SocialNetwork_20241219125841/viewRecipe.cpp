void Recipe::viewRecipe(const string &recipeName) {
    if (recipes.find(recipeName) != recipes.end()) {
        cout << "Recipe Name: " << recipeName << endl;
        cout << "Details: " << recipes[recipeName] << endl;
    } else {
        cout << "Recipe not found!" << endl;
    }
}