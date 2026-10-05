void AppController::viewAllPreferences() {
    auto preferences = userProfile.getPreferences();
    if (preferences.empty()) {
        cout << "No preferences added yet." << endl;
    } else {
        cout << "\nYour Preferences:\n";
        for (auto it = preferences.begin(); it != preferences.end(); ++it) { 
            cout << "Genre: " << it->first << "\nArtists: ";
            for (int i = 0; i < it->second.size(); i++) {
                cout << it->second[i];
                if (i < it->second.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
}