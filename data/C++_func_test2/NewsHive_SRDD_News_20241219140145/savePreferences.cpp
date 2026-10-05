void UserPreferences::savePreferences() {
    ofstream file("preferences.txt");
    if (file.is_open()) {
        for (int i = 0; i < preferences.size(); i++) {
            file << preferences[i] << endl;
        }
        file.close();
    }
}