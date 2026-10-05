void Recipe::addRecipe() {
    string recipeDetails;
    string recipeName;
    
    cout << "Enter the name of the recipe: ";
    getline(cin, recipeName);
    cout << "Enter the details of the recipe: ";
    getline(cin, recipeDetails);
    recipes[recipeName] = recipeDetails;
    cout << "Recipe added successfully!" << endl;
}