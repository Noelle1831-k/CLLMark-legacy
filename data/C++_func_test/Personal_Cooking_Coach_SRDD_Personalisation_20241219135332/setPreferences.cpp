void UserPreferences::setPreferences() {
    string input;
    cout << "Enter your dietary preferences (type 'done' when finished): ";
    while (cin >> input && "done" != input) {
        preferences.push_back(input);
    }
}