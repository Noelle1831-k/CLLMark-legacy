void User::shareRecipe() {
    string recipeName;
    cout << "Enter the name of the recipe to share: ";
    getline(cin, recipeName);
    cout << "Recipe '" << recipeName << "' shared with the community!" << endl;
}