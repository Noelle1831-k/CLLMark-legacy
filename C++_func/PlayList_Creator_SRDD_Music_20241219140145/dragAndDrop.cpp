void UserInterface::dragAndDrop(Playlist& playlist, const Song& song) {
    playlist.addSong(song);
    cout << "Added " << song.getTitle() << " to " << playlist.getName() << endl;
}