void loadTrack() {
    printf("Loading track...\n");
    char trackName[50];
    FILE *trackFile = fopen("track_data.txt", "r");
    if (trackFile) {
        fscanf(trackFile, "%s", trackName);
        printf("Track loaded: %s\n", trackName);
        fclose(trackFile);
    } else {
        printf("Failed to load track. Using default track.\n");
    }
}