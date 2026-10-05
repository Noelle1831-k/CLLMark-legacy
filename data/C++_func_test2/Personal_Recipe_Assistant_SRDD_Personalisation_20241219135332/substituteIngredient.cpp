void Recipe::substituteIngredient(string oldIngredient, string newIngredient, float quantity, string unit) {
    if (ingredients.find(oldIngredient) != ingredients.end()) {
        ingredients.erase(oldIngredient);
        ingredients[newIngredient] = make_pair(quantity, unit);
    }
}