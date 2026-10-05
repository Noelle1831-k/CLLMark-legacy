void User::viewProfile() {
    cout << "===============================" << endl;
    cout << "Username: " << username << endl;
    cout << "Bio: " << bio << endl;
    cout << "Favorite Recipes: ";
    for (int i = 0; i < favoriteRecipes.size(); i++) {
        cout << favoriteRecipes[i];
        if (i < favoriteRecipes.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "===============================" << endl;
}