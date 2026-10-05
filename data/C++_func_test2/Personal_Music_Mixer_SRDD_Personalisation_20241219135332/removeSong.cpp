void Playlist::removeSong(const string& song) {
    playlist.erase(remove(playlist.begin(), playlist.end(), song), playlist.end());
}