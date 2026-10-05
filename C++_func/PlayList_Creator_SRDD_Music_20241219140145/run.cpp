void Application::run() {
    ui.displayLibrary(library);
    ui.dragAndDrop(playlist, library.getLibrary()[0]);
    ui.addTagToPlaylist(playlist, "Chill");
    ui.displayPlaylist(playlist);
    ui.removeSongFromPlaylist(playlist, "Song1");
    ui.displayPlaylist(playlist);
}