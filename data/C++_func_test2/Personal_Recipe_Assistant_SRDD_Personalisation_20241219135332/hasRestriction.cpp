bool UserPreferences::hasRestriction(const string& restriction) const {
    return find(dietaryRestrictions.begin(), dietaryRestrictions.end(), restriction) != dietaryRestrictions.end();
}