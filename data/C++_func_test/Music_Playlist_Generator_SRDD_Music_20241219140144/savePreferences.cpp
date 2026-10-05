void UserPreferences::savePreferences() {
    ofstream outfile("preferences.txt");
    for (vector<string>::iterator it = preferences.begin(); it != preferences.end(); ++it) {
        outfile << *it << endl;
    }
    outfile.close();
}