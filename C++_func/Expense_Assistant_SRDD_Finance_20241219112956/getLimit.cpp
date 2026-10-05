double Budget::getLimit(const string& category) const {
    if (limits.find(category) != limits.end()) {
        return limits.at(category);
    }
    return 0.0;
}