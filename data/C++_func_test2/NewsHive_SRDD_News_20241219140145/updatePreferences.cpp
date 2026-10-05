void UserPreferences::updatePreferences() {
    cout << "Enter your new preferences (comma-separated): ";
    string input;
    cin.ignore();
    getline(cin, input);
    preferences.clear();
    stringstream ss(input);
    string preference;
    while (getline(ss, preference, ',')) {
        preferences.push_back(preference);
    }
    savePreferences();
}