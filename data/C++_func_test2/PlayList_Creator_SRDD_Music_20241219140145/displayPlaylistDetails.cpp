void Playlist::displayPlaylistDetails() const {
    cout << "Playlist: " << name << endl;
    cout << "Tags: ";
    for (vector<string>::const_iterator it = tags.begin(); it != tags.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (vector<Song>::const_iterator it = songs.begin(); it != songs.end(); ++it) {
        it->displaySongDetails();
    }
}