void viewRecipes() {
        cout << "Available Recipes: " << endl;
        for (int i = 0; i < recipes.size(); i++) {
            cout << i + 1 << ". " << recipes[i].getRecipeName() << endl;
        }
    }