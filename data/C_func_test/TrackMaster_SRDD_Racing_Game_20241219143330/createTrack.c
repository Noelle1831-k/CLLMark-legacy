void createTrack() {
    printf("Creating a new track...\n");
    int trackLength = rand() % 1000 + 500;
    int trackDifficulty = rand() % 5 + 1; 
    printf("Track length: %d meters\n", trackLength);
    printf("Track difficulty: %d (1 = easy, 5 = hard)\n", trackDifficulty);
}