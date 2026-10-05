int main(int argc, char *argv[]) {
    UserPreferences userPrefs;
    MusicAnalyzer musicAnalyzer;
    PlaylistGenerator playlistGen;
    MusicPlayerExporter playerExporter;
    userPrefs.loadPreferences();
    musicAnalyzer.analyzeMusic();
    vector<string> recommendedTracks = musicAnalyzer.recommendTracks();
    playlistGen.generatePlaylist(recommendedTracks);
    playlistGen.displayPlaylist();
    playerExporter.exportToPlayer();
    return 0;
}