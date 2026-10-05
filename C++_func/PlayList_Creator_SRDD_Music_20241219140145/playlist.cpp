Application::Application() : playlist("My Playlist") {
    library.addSong(Song("Song1", "Artist1", 210));
    library.addSong(Song("Song2", "Artist2", 180));
    library.addSong(Song("Song3", "Artist3", 240));
}