int main(void) {
    UserPreferences prefs;
    MusicAnalyzer analyzer;
    PlaylistGenerator generator = { .trackCount = 0 }; 
    MusicExporter exporter;
    handleUserInput(&prefs, &analyzer, &generator, &exporter);
    return 0;
}