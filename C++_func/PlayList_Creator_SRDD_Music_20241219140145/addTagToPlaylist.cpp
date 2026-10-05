void UserInterface::addTagToPlaylist(Playlist& playlist, const string& tag) {
    playlist.addTag(tag);
    cout << "Added tag '" << tag << "' to " << playlist.getName() << endl;
}