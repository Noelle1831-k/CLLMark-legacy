void UserPreferences::removePreference(const string& preference) {
    for (vector<string>::iterator it = preferences.begin(); it != preferences.end(); ++it) {
        if (*it == preference) {
            preferences.erase(it);
            break;
        }
    }
}