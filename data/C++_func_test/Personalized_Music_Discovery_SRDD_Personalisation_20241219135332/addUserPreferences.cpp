void AppController::addUserPreferences() {
    string genre, artist;
    cout << "Enter your favorite genre: ";
    cin >> genre;
    cout << "Enter your favorite artist: ";
    cin >> artist;
    userProfile.addPreference(genre, artist);
    cout << "Preference added successfully!" << endl;
}