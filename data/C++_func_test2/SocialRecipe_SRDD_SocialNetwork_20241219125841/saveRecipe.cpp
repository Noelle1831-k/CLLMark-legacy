void User::saveRecipe() {
    string recipeName;
    cout << "Enter the name of the recipe to save: ";
    getline(cin, recipeName);
    favoriteRecipes.push_back(recipeName);
    cout << "Recipe saved successfully!" << endl;
}