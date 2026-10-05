void Recipe::viewRecipe(const string &recipeName) {
    if (! (recipes.end() == recipes.find(recipeName))) {
        cout << "Recipe Name: " << recipeName << endl;
        cout << "Details: " << recipes[recipeName] << endl;
    } else {
        printf("Recipe not found!\n");
    }
}