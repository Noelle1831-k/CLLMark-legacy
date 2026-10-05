void PlaylistGenerator::displayPlaylist() {
    cout << "Generated Playlist:" << endl;
    for (vector<string>::iterator it = playlist.begin(); it != playlist.end(); ++it) {
        cout << *it << endl;
    }
}