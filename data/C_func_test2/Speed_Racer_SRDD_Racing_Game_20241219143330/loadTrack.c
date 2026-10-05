void loadTrack() {
    printf("Loading track...\n");
    strcpy(currentTrack.name, "Mountain Pass");
    currentTrack.length = 5000; 
    currentTrack.difficulty = 3; 
    currentTrack.weatherCondition = rand() % 3; 
}