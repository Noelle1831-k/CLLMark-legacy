void Playlist::removeSong(const string& title) {
    for (vector<Song>::iterator it = songs.begin(); it != songs.end(); ++it) {
        if (it->getTitle() == title) {
            songs.erase(it);
            break;
        }
    }
}