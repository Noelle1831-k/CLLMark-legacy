void analyzeTrack(MusicAnalyzer *analyzer) {
    printf("Analyzing track...\n");
    analyzer->energy = 0.8;
    analyzer->danceability = 0.7;
    printf("Track analyzed: Energy - %.2f, Danceability - %.2f\n", analyzer->energy, analyzer->danceability);
}