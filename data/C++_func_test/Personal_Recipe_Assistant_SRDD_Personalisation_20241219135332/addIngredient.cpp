void Recipe::addIngredient(string ingredient, float quantity, string unit) {
    ingredients[ingredient] = make_pair(quantity, unit);
}