void UserPreferences::updatePreferences(const string& categories) {
    preferences = Utility::splitString(categories, ',');
}