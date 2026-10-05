void UserPreferences::loadPreferences() {
    ifstream file("preferences.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            preferences.push_back(line);
        }
        file.close();
    }
}