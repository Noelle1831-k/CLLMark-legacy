void UserPreferences::setPreferences() {
    string input;
    cout << "Enter your dietary preferences (type 'done' when finished): ";
    while (cin >> input && input != "done") {
        preferences.push_back(input);
    }
}