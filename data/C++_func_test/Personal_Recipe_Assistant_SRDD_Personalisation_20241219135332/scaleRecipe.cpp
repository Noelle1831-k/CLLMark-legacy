void Recipe::scaleRecipe(float factor) {
    for (map<string, pair<float, string>>::iterator it = ingredients.begin(); it != ingredients.end(); ++it) {
        it->second.first *= factor;
    }
}