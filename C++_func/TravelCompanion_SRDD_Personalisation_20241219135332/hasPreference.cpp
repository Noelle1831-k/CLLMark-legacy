bool UserPreferences::hasPreference(const string& preference) const {
    return find(preferences.begin(), preferences.end(), preference) != preferences.end();
}