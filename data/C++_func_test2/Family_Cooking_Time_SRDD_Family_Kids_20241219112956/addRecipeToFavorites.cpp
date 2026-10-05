void addRecipeToFavorites() {
        int recipeIndex;
        cout << "Enter recipe number to add to favorites: ";
        cin >> recipeIndex;
        if (recipeIndex > 0 && recipeIndex <= recipes.size()) {
            userProfile.addFavoriteRecipe(recipes[recipeIndex - 1]);
            cout << "Recipe added to favorites!" << endl;
        } else {
            cout << "Invalid recipe number!" << endl;
        }
    }