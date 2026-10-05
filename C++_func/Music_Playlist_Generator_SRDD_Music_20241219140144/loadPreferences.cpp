void UserPreferences::loadPreferences() {
    ifstream infile("preferences.txt");
    string line;
    while (getline(infile, line)) {
        preferences.push_back(line);
    }
    infile.close();
}