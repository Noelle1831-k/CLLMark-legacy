void UserPreferences::addPreference(const string& preference) {
    preferences.push_back(preference);
    cout << "Preference added: " << preference << endl;
}