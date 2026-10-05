void Recipe::generateRecipe(const vector<string>& preferences) {
    cout << "Generating recipe based on preferences: ";
    for (int i = 0; i < preferences.size(); i++) {
        cout << preferences[i] << " ";
    }
    cout << endl;
    cout << "Recipe: Quinoa Salad with Avocado and Black Beans" << endl;
    cout << "Ingredients: Quinoa, Avocado, Black Beans, Lime, Cilantro" << endl;
    cout << "Instructions: Cook quinoa, mix with other ingredients, and serve." << endl;
}