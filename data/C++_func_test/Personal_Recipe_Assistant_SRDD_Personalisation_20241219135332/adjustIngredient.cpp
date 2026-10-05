void Recipe::adjustIngredient(string ingredient, float newQuantity) {
    if (ingredients.find(ingredient) != ingredients.end()) {
        ingredients[ingredient].first = newQuantity;
    }
}