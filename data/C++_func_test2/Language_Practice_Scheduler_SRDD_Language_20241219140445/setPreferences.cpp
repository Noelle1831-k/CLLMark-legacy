void User::setPreferences() {
    cout << "Enter your learning preferences (type 'done' to finish): ";
    string preference;
    while (cin >> preference && preference != "done") {
        preferences.push_back(preference);
    }
}