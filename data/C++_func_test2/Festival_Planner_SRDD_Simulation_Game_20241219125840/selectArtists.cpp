void Player::selectArtists(std::vector<Artist>& artists) {
    int numArtists;
    cout << "Enter the number of artists you want to book: ";
    cin >> numArtists;
    for (int i = 0; i < numArtists; i++) {
        string name, genre;
        int popularity;
        cout << "Enter the name of artist " << i + 1 << ": ";
        cin >> name;
        cout << "Enter the genre of artist " << i + 1 << ": ";
        cin >> genre;
        cout << "Enter the popularity of artist " << i + 1 << " (1-100): ";
        cin >> popularity;
        artists.push_back(Artist(name, genre, popularity, true));
    }
}