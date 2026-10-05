void UserPreferences::removePreference(const string& preference) {
    preferences.erase(remove(preferences.begin(), preferences.end(), preference), preferences.end());
}