bool Utils::isValidCategory(const string &category) {
    return regex_match(category, regex("^[a-zA-Z]+$"));
}