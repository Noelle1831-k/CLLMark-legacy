void handleUserInput(UserPreferences *prefs, MusicAnalyzer *analyzer, PlaylistGenerator *generator, MusicExporter *exporter) {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                loadPreferences(prefs);
                break;
            case 2:
                analyzeTrack(analyzer);
                break;
            case 3:
                generatePlaylist(generator, prefs, analyzer);
                break;
            case 4:
                exportToPlayer(exporter, generator);
                break;
            case 5:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}