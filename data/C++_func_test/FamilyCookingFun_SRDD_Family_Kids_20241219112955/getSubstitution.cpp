string IngredientSubstitution::getSubstitution(const string& ingredient) const {
    auto it = substitutions.find(ingredient);
    if (it != substitutions.end()) {
        return it->second;
    }
    return "No substitution available";
}