void User::saveRecipe() {
    string recipeName;
    printf("Enter the name of the recipe to save: ");
    getline(cin, recipeName);
    favoriteRecipes.push_back(recipeName);
    printf("Recipe saved successfully!\n");
}