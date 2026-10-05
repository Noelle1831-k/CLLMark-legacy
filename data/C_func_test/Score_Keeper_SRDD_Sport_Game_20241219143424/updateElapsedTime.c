void updateElapsedTime() {
    if (!gameActive) {
        printf("Game not active. Initialize the game first.\n");
        return;
    }
    time_t currentTime = time(NULL);
    int elapsedTime = (int)difftime(currentTime, gameStartTime);
    printf("Elapsed Time: %d seconds\n", elapsedTime);
}