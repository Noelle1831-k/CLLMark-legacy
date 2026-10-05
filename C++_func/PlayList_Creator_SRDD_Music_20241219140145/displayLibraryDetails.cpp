void MusicLibrary::displayLibraryDetails() const {
    cout << "Music Library:" << endl;
    for (vector<Song>::const_iterator it = library.begin(); it != library.end(); ++it) {
        it->displaySongDetails();
    }
}