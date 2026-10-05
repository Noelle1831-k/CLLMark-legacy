void initializeGame() {
    playerCar = createCar();
    currentTrack = createTrack(rand() % MAX_TRACKS);
    currentScore = 0;
    highScore = 0;
    printf("Welcome to Drift Rivals!\n");
    printf("Get ready to drift and set a new high score!\n");
}