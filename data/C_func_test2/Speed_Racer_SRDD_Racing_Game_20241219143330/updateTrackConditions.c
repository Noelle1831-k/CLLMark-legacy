void updateTrackConditions() {
    printf("Updating track conditions...\n");
    if (rand() % 10 < 2) { 
        currentTrack.weatherCondition = rand() % 3;
    }
}