void UserPreferences::removeRestriction(string restriction) {
    dietaryRestrictions.erase(remove(dietaryRestrictions.begin(), dietaryRestrictions.end(), restriction), dietaryRestrictions.end());
}