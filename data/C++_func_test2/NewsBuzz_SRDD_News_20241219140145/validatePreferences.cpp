bool UserPreferences::validatePreferences() {
    if (preferences.empty()) {
        cout << "No preferences loaded. Default preferences will be used." << endl;
        return false;
    }
    return true;
}