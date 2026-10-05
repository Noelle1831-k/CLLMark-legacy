void UserPreferences::loadPreferences() {
    preferences.push_back("Market");
    preferences.push_back("Sports");
    preferences.push_back("Technology");
    if (!validatePreferences()) {
        preferences.push_back("General");
    }
}