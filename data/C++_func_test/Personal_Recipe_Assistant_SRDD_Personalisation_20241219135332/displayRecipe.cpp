void Recipe::displayRecipe() const {
    cout << "Recipe: " << name << endl;
    cout << "Ingredients:" << endl;
    for (map<string, pair<float, string>>::const_iterator it = ingredients.begin(); it != ingredients.end(); ++it) {
        cout << " - " << it->first << ": " << it->second.first << " " << it->second.second << endl;
    }
    cout << "Steps:" << endl;
    for (size_t i = 0; i < steps.size(); ++i) {
        cout << i + 1 << ". " << steps[i] << endl;
    }
}