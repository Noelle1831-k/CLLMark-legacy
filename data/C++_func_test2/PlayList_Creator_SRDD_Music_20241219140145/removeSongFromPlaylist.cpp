void UserInterface::removeSongFromPlaylist(Playlist& playlist, const string& title) {
    playlist.removeSong(title);
    cout << "Removed " << title << " from " << playlist.getName() << endl;
}