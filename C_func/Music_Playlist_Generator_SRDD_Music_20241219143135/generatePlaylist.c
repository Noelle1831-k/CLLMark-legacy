void generatePlaylist(PlaylistGenerator *generator, UserPreferences *prefs, MusicAnalyzer *analyzer) {
    printf("Generating playlist...\n");
    if (strcmp(prefs->genre, "Rock") == 0 && analyzer->energy > 0.5) {
        addTrackToPlaylist(generator, "Rock Anthem");
    }
    printf("Playlist generated.\n");
}